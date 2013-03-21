#ifndef __PROCESS_
#define __PROCESS_

#include <iostream>
#include <signal.h>
#include <unistd.h>

class Process 
{
    static char *procdir;

    private:
        // Private data members and functions
        pid_t pid;
        char name[7]; // /proc/status/  

        int setName();

    public:
        // Public data members and functions
        Process(pid_t);

        // Accessors / Mutators
        char *getName(char *);

        // Process Monitoring        
        
        // Process Management
        int sendSignal(int);

};

#endif
