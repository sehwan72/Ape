#ifndef __SYS_
#define __SYS_

#include <stdio.h>

class Sys 
{
    private:
        unsigned long int totalTime;        

    public:
        static char *procdir;
        unsigned long int btime;
        unsigned long int childMax;
        unsigned long int clockTicks;
        unsigned long int openMax;
        unsigned long int streamMax;
        unsigned long int pageSize;
        unsigned long int runningProcesses;
        unsigned long int blockedProcesses;

        unsigned int totalCPU;

        char *version;

        Sys();
        ~Sys();

        int parseVersion(char **, int);
        unsigned long int updateStat();
        
        //int setTotalTime();

        static unsigned long int getTotalTime()
        {
            FILE *statfd;
            char statfile[30];
            unsigned long int cputime[10];
            unsigned long int total = 0;

            snprintf(statfile, sizeof statfile, "%s/stat", Sys::procdir);
            
            statfd = fopen(statfile,"r");
            if (statfd == NULL) {
                fprintf(stderr, "fopen error: %s\n", procdir);
                return -1;
            }

            fscanf(statfd, "%*s %lu %lu %lu %lu %lu %lu %lu %lu %lu %lu", 
                &cputime[0], &cputime[1], &cputime[2], &cputime[3],
                &cputime[4], &cputime[5], &cputime[6], &cputime[7],
                &cputime[8], &cputime[9]);
            fclose(statfd);

            int i;
            for (i = 0; i < 10; ++i) {
                total += cputime[i];
            }

            //this->totalTime = total;
            return total;
        }
};

#endif
