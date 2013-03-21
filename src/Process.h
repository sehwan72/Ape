#ifndef __PROCESS_
#define __PROCESS_

#include <iostream>
#include <signal.h>
#include <unistd.h>

struct stat {
    long unsigned int total_time;
    long unsigned int utime;
};

class Process 
{
    private:
        // Private data members and functions
        pid_t pid;
        char name[7]; // /proc/status/  

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

};

#endif
