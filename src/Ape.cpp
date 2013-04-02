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
    // TODO: iterate(?) through processMap and delete
    //       all entries

    delete this->system;
}

int Ape::upsertProcess(pid_t pid)
{
    std::map<int, Process*>::iterator it = this->processMap.find(pid);
    Process *p;
    if (it == processMap.end()) {
        
        // Insert if not present
        p = new Process(pid);
        this->processMap[pid] = p;
        this->processList.push_back(&processMap[pid]);
    
    } else {
        
        // Otherwise, update
        //processMap[pid]->updateStat();
        processMap[pid]->setCPUUsage();
    }
}

void Ape::sort(SortBy s)
{
    bool (*comp)(Process **, Process**);

    switch (s) {
        case CPU:
            comp = Ape::compareByCPU;
            break;
    }
    
    std::stable_sort(this->processList.begin(), 
                     this->processList.end(),
                     comp);
}

void Ape::update() 
{
    // Iterate through /proc, read every directory
    // that represents a process, and add the
    // corresponding Process to map and vector
    struct dirent *direntry;
    DIR *dir = opendir(Sys::procdir);
    if (dir == NULL) {
        perror("opendir failure");
        return;
    }
    
    char *end;
    unsigned long int entry;
    while ((direntry = readdir(dir)) != NULL) {
        entry = strtol(direntry->d_name, &end, 10);
        if (entry != 0)
            this->upsertProcess(entry);
    }
    
    closedir(dir);
    
    /*int i, j;
    for (i = 0, j = this->processList.size(); i < j; ++i) {
        //(*processList[i])->setCPUUsage();
        //(*processList[i])->u_cpu = j - i;
        //(*processList[i])->setCPUUsage();
    }*/
}

void Ape::printProcesses(SortBy s) 
{
    this->sort(s);
    int i, j;
    
    printf("USER\tPID\tU_CPU\tS_CPU\tVSZ\tRSS\tTTY\tSTAT\tSTART\tCOMMAND\n\n");
    for (i = 0, j = this->processList.size(); i < j; ++i) {
        stat_t *stat = (*processList[i])->getStatPtr();
        if (((*processList[i])->u_cpu + (*processList[i])->s_cpu == 0) && 
                ((*processList[i])->s_cpu == 0)) 
            continue;

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
        //printf("%20s::%d\t(#):%d\n", 
        //        (*processList[i])->getStatPtr()->name,
        //        (*processList[i])->getStatPtr()->pid,
        //        i
        //        );
    }
    //refresh();
}
