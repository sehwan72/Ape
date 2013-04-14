#include <algorithm>


//#include <curses.h>
#include <stdlib.h> // strtol
#include <dirent.h>

#include "Ape.h"

Ape::Ape()
{
    this->system = new Sys();
    this->update();
}

Ape::~Ape()
{
    // Delete all Processes
    std::map<int, Process *>::iterator it;
    for (it = processMap.begin(); it != processMap.end(); ++it)
        this->removeProcess(it->second->getStatPtr()->pid);

    // Delete Sys instantiation
    delete this->system;
}

int Ape::removeProcess(pid_t pid)
{
    // Remove link from vector
    int i, j;
    for (i = 0, j = processList.size(); i < j; ++i)
        if ((*processList[i])->pid == pid)
            break;

    if (i == j) return -1; // Process not found
    processList.erase(processList.begin() + i); // Remove the process from the list

    // Remove from map
    delete processMap[pid];
    processMap.erase(pid);

    return 0;
}

int Ape::upsertProcess(pid_t pid)
{
    int rcode;
    std::map<int, Process*>::iterator it = this->processMap.find(pid);
    Process *p;
    if (it == processMap.end()) {
        
        // Insert if not present
        p = new Process(pid);
        this->processMap[pid] = p;
        this->processList.push_back(&processMap[pid]);
    
    } else {
        
        // Otherwise, update
        rcode = processMap[pid]->update();

        // If something went wrong, assume the process is
        // dead and return the pid of the dead process to 
        // be cleaned up
        if (rcode != 0) return pid;
    }

    return 0;
}

void Ape::sort(SortBy s)
{
    bool (*comp)(Process **, Process**);

    switch (s) {
        case CPU:
            comp = Ape::compareByCPU;
            break;

        case PID:
            comp = APE::compareByPID;
            break;
    }
    
    std::stable_sort(this->processList.begin(), 
                     this->processList.end(),
                     comp);
}

int Ape::update() 
{
    int rcode;
    unsigned int totalCPU = 0;

    // Set all processes up for updating
    std::map<int, Process *>::iterator it;
    for (it = processMap.begin(); it != processMap.end(); ++it)
        it->second->resetUpdated();


    // Iterate through /proc, read every directory
    // that represents a process, and add the
    // corresponding Process to map and vector
    struct dirent *direntry;
    DIR *dir = opendir(Sys::procdir);
    if (dir == NULL) {
        perror("opendir failure");
        return -1;
    }
    
    // Upsert a Process for each pid in /proc/pid/
    char *end;
    unsigned long int entry;
    while ((direntry = readdir(dir)) != NULL) {
        entry = strtol(direntry->d_name, &end, 10);
        if (entry != 0) {
            rcode = this->upsertProcess(entry);

            // Clean up any processes that are causing trouble
            if (rcode != 0) removeProcess(rcode);
        }
    }

    // Close the directory when done
    closedir(dir);
    

    // Remove all processes that were not updated (no procfs dir)
    for (it = processMap.begin(); it != processMap.end(); ++it) {
        if (it->second->wasUpdated() == false)
            this->removeProcess(it->second->pid);
        else
            totalCPU += it->second->u_cpu + it->second->s_cpu;
    }

    return 0;
}

void Ape::printProcesses(SortBy s) 
{
    this->sort(s);
    int i, j;
    
    printf("USER\tPID\tCPU\tS_CPU\tVSZ\tRSS\tTTY\tSTAT\tSTART\tCOMMAND\n\n");
    for (i = 0, j = this->processList.size(); i < j; ++i) {
        stat_t *stat = (*processList[i])->getStatPtr();
        //if (((*processList[i])->u_cpu + (*processList[i])->s_cpu == 0) && 
        //        ((*processList[i])->s_cpu == 0)) 
        //    continue;

        printf("%s\t%d\t%.1f\t%.1f\t%lu\t%lu\t%d\t%c\t%lu\t%s\n",
            "tim",
            stat->pid,
            ((*processList[i])->u_cpu + (*processList[i])->s_cpu),
            (*processList[i])->s_cpu,
            stat->vss,
            stat->rss,
            stat->tty_nr,
            stat->state,
            stat->start_time,
            stat->name
            );
    }
}

void Ape::sortByParent()
{
    std::vector<Process **> tempVector1;
    std::vector<Process **> tempVector2;

    int i, j;
    for (i = 0, j = processList.size(); i < j; ++i)
        if ((*processList[i])->pid == 1)
            break;

    tempVector1.push_back(processList[i]);
    addChildren(&tempVector1, (*processList[i])->pid);

    tempVector2 = processList;
    processList = tempVector1;
    tempVector2.clear();
}

void Ape::addChildren(std::vector<Process **> *tempVector, const unsigned long pid)
{   
    int i, j;
    for (i = 0, j = processList.size(); i < j; ++i) {
        if ((*processList[i])->getStatPtr()->ppid == pid) {
            tempVector->push_back(processList[i]);
            addChildren(tempVector,(*processList[i])->pid); 
        }
    }
}
