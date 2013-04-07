#include <string>
#include <strings.h>
#include <string.h>
#include <sys/types.h> // O_RDONLY
#include <sys/stat.h>
#include <fcntl.h> // open

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#include "Process.h"
#include "Sys.h"

// Offsets
#define NAME_OFFSET 6
#define DEBUG 1

// Default constructor for class Process
Process::Process(pid_t pid) 
{   
    this->pid = pid;

    // Get constant fields out of /proc
    //this->setName();   

    // Set initial cpu time
    this->u_cpu = 0L;
    this->s_cpu = 0L;
    this->last_cpu = Sys::getTotalTime();
    this->updateStatus();
    this->updated = (this->updateStat() == 0);
}

int Process::resetUpdated()
{
    this->updated = false;
    return 0;
}

int Process::update()
{
    int rcode = this->setCPUUsage();

    // Return if something went wrong, this could indicate 
    // the process no longer exists
    if (rcode != 0) return rcode; 

    this->updated = true;
    return 0;
}

int Process::wasUpdated()
{
    return this->updated;
    return 0;
}

int Process::getMemoryMap(char **buffer, int buf_size)
{
    char mappath[20];
    int fd;

    snprintf(mappath, sizeof mappath, "%s/%d/maps", 
            Sys::procdir, (int)this->pid);

    fd = open(mappath, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "open error: %s", mappath);
        return -1;
    }

    bzero(*buffer, buf_size);
    read(fd, *buffer, buf_size);
    close(fd);
}

// Process Initialization
// not used, caused memcheck fail
// use getStatPtr()->name instead
int Process::setName()
{
    FILE *procfd;
    char procfile[20];

    snprintf(procfile, sizeof procfile, "%s/%d/status", 
        Sys::procdir, (int)this->pid);
    
    procfd = fopen(procfile,"r");
    if (procfd == NULL) {
        fprintf(stderr, "fopen error: %s", procfile);
        return -1;
    }

    fseek(procfd, NAME_OFFSET, SEEK_SET);
    fscanf(procfd, "%s", this->name);
    fclose(procfd);
}

stat_t *Process::getStatPtr()
{
    return &this->stat;
}

status_t *Process::getStatusPtr()
{
    return &this->status;
}

// Process Monitoring
void Process::printStat() {
    printf("Statistics for `%s`:\n"
           "--------------------\n"
           "pid:      %d\n"
           "exe:      %s\n"
           "state:    %c\n"
           "ppid:     %d\n"
           "pgrp:     %d\n"
           "sid:      %d\n"
           "tty_nr:   %d\n"
           "tty_pgrp: %d\n"
           "flags:    %d\n"
           "min_flt:  %d\n"
           "cmin_flt: %d\n"
           "maj_flt:  %d\n"
           "cmaj_flt: %d\n"
           "utime:    %lu\n"
           "stime:    %lu\n"
           "cutime:   %lu\n"
           "cstime:   %lu\n"
           "priority: %d\n"
           "niceness: %d\n"
           "threads:  %d\n"
           "start:    %lu\n"
           "vss:      %lu\n"
           "rss:      %lu\n"
           "\n",
            name,
            stat.pid,        stat.name,     stat.state,    stat.ppid, 
            stat.pgrp,       stat.sid,      stat.tty_nr,   stat.tty_pgrp, 
            stat.flags,      stat.min_flt,  stat.cmin_flt, stat.maj_flt, 
            stat.cmaj_flt,   stat.utime,    stat.stime,    stat.cutime, 
            stat.cstime,     stat.priority, stat.niceness, stat.threads,
            stat.start_time, stat.vss,      stat.rss
           );
}

int Process::setCPUUsage() 
{
    int rcode;
    unsigned long int old_utime,
        old_stime,
        old_cpu_time;

    old_utime = stat.utime;
    old_stime = stat.stime;
    old_cpu_time = last_cpu;
    this->last_cpu = Sys::getTotalTime();
    
    rcode = this->updateStat();
    if (rcode != 0) return rcode; // If an error, return the error up the chain

    unsigned long int time = this->last_cpu - old_cpu_time;
    //printf("SYS_TIME: %lu\n", time);

    if (time == 0) {
        // Not enough time has passed, set CPU usage to something bogus
        this->u_cpu= 999;
        
        // Return 0 since process is still alive
        return 0;
    }

    this->u_cpu = 100 * (stat.utime - old_utime) / (time);
    this->s_cpu = 100 * (stat.stime - old_stime) / (time);
    
    return 0;
}

int Process::updateStatus()
{
    FILE *procfd;
    char procfile[80];

    snprintf(procfile, sizeof procfile, "%s/%d/status",
            Sys::procdir, (int)this->pid);

    procfd = fopen(procfile, "r");
    if (procfd == NULL) {
        fprintf(stderr, "fopen error: %s\n", procfile);
        return -1;
    }

    char buf[256];
    fgets(buf, 256, procfd);
    fgets(buf, 256, procfd);
    fgets(buf, 256, procfd);
    fgets(buf, 256, procfd);
    fgets(buf, 256, procfd);
    fgets(buf, 256, procfd);
    fgets(buf, 256, procfd);

    sscanf(buf, "Uid:\t%lu", &this->status.uid);
    fclose(procfd);
    return 0;
}

int Process::updateStat() 
{
    FILE *procfd;
    char procfile[80];

    // Get the stat path for this Process
    snprintf(procfile, sizeof procfile, "%s/%d/stat", 
        Sys::procdir, (int)this->pid);
    
    // Open the stat file for the Process
    procfd = fopen(procfile,"r");
    if (procfd == NULL) {
        fprintf(stderr, "fopen error: %s\n", procfile);
        return -1; // Return -1 if fopen error, this could indicate the process does not exist
    }

    // Parse /proc/pid/stat for the following fields
    fscanf(procfd, 
        "%d %s %c %d %d %d %d %d %d %d %d %d %d %lu %lu %lu %lu %d %d %d %*s %lu %lu %lu",
        &stat.pid,        stat.name,      &stat.state,    &stat.ppid, 
        &stat.pgrp,       &stat.sid,      &stat.tty_nr,   &stat.tty_pgrp, 
        &stat.flags,      &stat.min_flt,  &stat.cmin_flt, &stat.maj_flt, 
        &stat.cmaj_flt,   &stat.utime,    &stat.stime,    &stat.cutime, 
        &stat.cstime,     &stat.priority, &stat.niceness, &stat.threads,
        &stat.start_time, &stat.vss,      &stat.rss
        );

    // Close the file once we're finished
    fclose(procfd);
    return 0;
}

// Process Management
int Process::sendSignal(int signum)
{
    return kill(this->pid, signum);
}

// *Note* - This currently will halt execution 
// of the process
int Process::generateCore() {
    sendSignal(11);
}

int Process::getOpenFiles(std::vector<char *> *fileList)
{
    char path[80];
    struct dirent *direntry;
    char *end;
    unsigned long int entry;
    char *symbolicLink;
    
    snprintf(path, sizeof(path), "%s/%d/fd", Sys::procdir, this->pid);
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir failure");
        return -1;
    }
    
    int fd, r;
    while ((direntry = readdir(dir)) != NULL) {
        std::string str(direntry->d_name);
        
        if ((str.find_first_not_of( "0123456789" )) != std::string::npos) continue;
        
        symbolicLink = (char *)malloc(80);
        bzero(symbolicLink, 80);
        snprintf(path, sizeof(path), "%s/%d/%s", Sys::procdir, this->pid, direntry->d_name);
        r = readlink(path, symbolicLink, 79);
        printf("%s -> ", (r < 0) ? strerror(errno) : "0");
        printf("%s -> %s\n", path, symbolicLink);
        fileList->push_back(symbolicLink);
    }
    
    closedir(dir);
    
    return 0;
}
