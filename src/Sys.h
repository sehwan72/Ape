#ifndef __SYS_
#define __SYS_

class Sys 
{
    

    private:
        unsigned long int totalTime;

    public:
		static char *procdir;

        Sys();
        void setTotalTime();
        unsigned long int getTotalTime();
};

#endif
