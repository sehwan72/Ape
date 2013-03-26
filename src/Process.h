#ifndef __PROCESS_
#define __PROCESS_

#include <iostream>
#include <signal.h>
#include <unistd.h>

// From /proc/<pid>/stat
typedef struct {
    int pid;           // Process ID
    char name[80];     // Executable name
    char state;        // State (R, S, D, Z, T)
    int ppid;          // Parent Process ID
    int pgrp;          // PGRP
    int sid;           // Session ID
    int tty_nr;        // Current TTY
    int tty_pgrp;      // PGRP of the TTY
    int flags;         // Task Flags
    int min_flt;       // Minor Faults
    int cmin_flt;      // Minor faults with children
    int maj_flt;       // Major Faults
    int cmaj_flt;      // Major faults with children

    // Time on cpu
    unsigned long int utime;  // Time in user mode
    unsigned long int stime;  // Time in kernel mode
    unsigned long int cutime; // Time in user mode with children
    unsigned long int cstime; // Time in kernel mode with children

    int priority;      // Process priority
    int niceness;      // Niceness
    int threads;       // Thread count
    int O;             // Zero field
    unsigned long int start_time; // Start time from boot in nanoseconds

    // Memory usage
    unsigned long int vss;  // Virtual memory usage in pages
    unsigned long int rss;        // Resident memory usage in pages

} stat_t;

class Process 
{
    private:
        // Private data members and functions
        pid_t  pid;
        char   name[7];  
        stat_t stat;
        unsigned long int last_cpu;

        int setName();

    public:
        unsigned long int u_cpu; // User space cpu usage
        unsigned long int s_cpu; // Kernel space cpu usage
        
        // Public data members and functions
        Process(pid_t);

        // Accessors / Mutators
        char   *getName(char *);
        int     getCPUTime();
        stat_t *getStatPtr();

        // Process Monitoring        
        void printStat();
        void setCPUUsage();
        void updateStat();

        // Process Management
        int sendSignal(int);
        int generateCore();
};

#endif
