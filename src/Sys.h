#ifndef __SYS_
#define __SYS_

class Sys 
{
    private:
        unsigned long int totalTime;

    public:
        static char *procdir;

        Sys();
        int setTotalTime();
        unsigned long int getTotalTime();
};

#endif
