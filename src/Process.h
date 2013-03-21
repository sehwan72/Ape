#ifndef __PROCESS_
#define __PROCESS_

#include <iostream>
#include <signal.h>
#include <unistd.h>

class Process 
{
    private:
        // Private data members and functions
        pid_t pid;
        char name[7]; // /proc/pid/status/  


        int setName();
        int parseStat();

    public:
        // Public data members and functions
        Process(pid_t);

        // Accessors / Mutators
        char *getName(char *);
        int   getCPUTime();

        // Process Monitoring        
        
        // Process Management
        int sendSignal(int);
        int generateCore();
};

#endif
