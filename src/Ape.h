#ifndef __APE_
#define __APE_

#include <map>
#include <vector>
#include <string.h>

#include "Process.h"
#include "Sys.h"

enum SortBy { CPU, MEM, NAME, PID, PPID, TTY, USER, VSZ, RSS, UCPU, SCPU, STATE, START };

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
        void getProcessesUsingFile(std::vector<Process *> *, char *);
      
        void sortByParent();
        void addChildren(std::vector<Process **> *, const unsigned long, int level = 1);

        static bool compareByPID(Process **p1, Process **p2) {
            return (*p1)->getStatPtr()->pid > 
                   (*p2)->getStatPtr()->pid;
        }
        
        static bool compareByCPU(Process **p1, Process **p2) {   
            return ((*p1)->u_cpu + (*p1)->s_cpu) > 
                   ((*p2)->u_cpu + (*p2)->s_cpu);
        }

        static bool compareByUsername(Process **p1, Process **p2) {
            return (std::string)(*p1)->getStatusPtr()->username > (std::string)(*p2)->getStatusPtr()->username;
        }

        static bool compareByVSZ(Process **p1, Process **p2) {
            return ((*p1)->getStatPtr()->vss >
                    (*p2)->getStatPtr()->vss);
        }

        static bool compareByRSS(Process **p1, Process **p2) {
            return ((*p1)->getStatPtr()->rss >
                    (*p2)->getStatPtr()->rss);
        }

        static bool compareByTTY(Process **p1, Process **p2) {
            return ((*p1)->getStatPtr()->tty_nr >
                    (*p2)->getStatPtr()->tty_nr);
        }

        static bool compareByState(Process **p1, Process **p2) {
            return ((*p1)->getStatPtr()->state >
                    (*p2)->getStatPtr()->state);
        }

        static bool compareByStartTime(Process **p1, Process **p2) {
            return ((*p1)->getStatPtr()->start_time >
                    (*p2)->getStatPtr()->start_time);
        }

        static bool compareByName(Process **p1, Process **p2) {
            return (std::string)(*p1)->getStatPtr()->name > (std::string)(*p2)->getStatPtr()->name;
        }

        static bool compareByUCPU(Process **p1, Process **p2) {
            return ((*p1)->u_cpu >
                    (*p2)->u_cpu);
        }

        static bool compareBySCPU(Process **p1, Process **p2) {
            return ((*p1)->s_cpu >
                    (*p2)->s_cpu);
        }
};

#endif
