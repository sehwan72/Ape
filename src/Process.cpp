#include <stdio.h>

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
    this->setName();    
}

// Process Initialization
int Process::setName()
{
    FILE *procfd;
    char procfile[80];  // TODO: This is a hack, malloc this

    snprintf(procfile, sizeof procfile, "%s/%d/status", 
        Sys::procdir, (int)this->pid);
    
    procfd = fopen(procfile,"r");
    if (procfd == NULL) {
        perror("fopen error");
        return -1;
    }

    fseek(procfd, NAME_OFFSET, SEEK_SET);
    fscanf(procfd, "%s", this->name);
    fclose(procfd);

#if DEBUG
    printf("Finished init\n");
    printf("Name: %s\n", this->name);
#endif
}

// Get utime jiffies from /proc/pid/stat
int Process::parseStat() 
{

}


// Process Monitoring

// Process Management
int Process::sendSignal(int signum)
{
    return kill(this->pid, signum);
}

int Process::generateCore() {
    sendSignal(11);
}
