#ifndef __APE_
#define __APE_

#include <map>
#include <vector>

#include "Process.h"
#include "Sys.h"

enum SortBy { CPU, MEM, NAME, PID };

class Ape
{
    private:

    public:
        std::map<int, Process *> processMap;
        std::vector<Process **> processList;
        Sys *system;

        ~Ape();
        Ape();

        int update();

        int upsertProcess(pid_t);
        int removeProcess(pid_t);

        void sort(SortBy);
        void printProcesses(SortBy);
        
        static bool compareByCPU(Process **p1, Process **p2) {
            return ((*p1)->u_cpu + (*p1)->s_cpu) < 
                   ((*p2)->u_cpu + (*p2)->s_cpu);
        }
};

#endif
