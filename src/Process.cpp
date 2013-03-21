#include "Process.h"

// Set process directory
char *Process::procdir = "/proc";


// Default constructor for class Process
Process::Process(pid_t pid) 
{
    this->pid = pid;
}


// Process Monitoring



// Process Management
int Process::sendSignal(int signum)
{
    return kill(this->pid, signum);
}


