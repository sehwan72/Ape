#include "Process.h"

#include <stdio.h>

// Offsets
#define NAME_OFFSET 6
#define DEBUG 1

// Set process directory
char *Process::procdir = "/proc";


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

    snprintf(procfile, sizeof procfile, "%s/%d/status", Process::procdir, (int)pid);
    procfd = fopen(procfile,"r");
    fseek(procfd, NAME_OFFSET, SEEK_SET);
    fscanf(procfd, "%s", this->name);
    fclose(procfd);

#if DEBUG
    printf("Finished init\n");
    printf("Name: %s\n", this->name);
#endif
}


// Process Monitoring



// Process Management
int Process::sendSignal(int signum)
{
    return kill(this->pid, signum);
}


