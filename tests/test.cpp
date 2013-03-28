#include <curses.h>
#include <stdio.h>
#include "../src/Ape.h"
#include "../src/Process.h"
#include "../src/Sys.h"

int initTest();
int sendSignal();
int sysTest();
int testCore();
int procStatTest();
int procCPUTest();
int apeTest();
int fileTest();

int main()
{
    Ape a = Ape();
    
    initscr();
    clear();
    refresh();

    while (1) {
        a.update();
        a.printProcesses(CPU);
        //usleep(500 * 1000);
        sleep(1);
        clear();
        //refresh();
    }
    endwin();

    //initTest();
    //sysTest();
    //procStatTest();
    procCPUTest();
    //fileTest();
    //testCore();
    //sendSignal();
    //getchar();
}

int fileTest()
{
    Process p = Process(19710);
    std::vector<char *> fileList;
    p.getOpenFiles(&fileList);
    int i, j;
    
    
    printf("\n%d open files for current process: \n", fileList.size());
    for (i = 0, j = fileList.size(); i < j; ++i) {
        printf("%s\n", fileList[i]);
    }
    printf("\n");
}

int apeTest()
{
    Ape a = Ape();
    //a.addProcess(getpid());
  
    a.printProcesses(CPU);
    printf("Number of processes in map:    %d\n", a.processMap.size());
    printf("Number of processes in vector: %d\n", a.processList.size());
    printf("Process name from APE: %s\n\n", a.processMap[getpid()]->getStatPtr()->name);
}

int procCPUTest()
{
    Process p = Process(1049);
    //p.updateStat();
    p.setCPUUsage();
    printf("u_cpu: %lu\n"
           "s_cpu: %lu\n",
            p.u_cpu,
            p.s_cpu
           );
    //p.updateStat();
    sleep(1);
    p.setCPUUsage();
    printf("u_cpu: %lu\n"
           "s_cpu: %lu\n",
            p.u_cpu,
            p.s_cpu
           );
    sleep(1);
    p.setCPUUsage();
    printf("u_cpu: %lu\n"
           "s_cpu: %lu\n",
            p.u_cpu,
            p.s_cpu
           );
}

int procStatTest()
{
    Process p = Process(getpid());
    //p.updateStat();
    p.printStat();

    return 0;
}

int sendSignal() {
    Process p = Process(getpid());
    p.sendSignal(15); // Send a TERM signal

    return 0;
}

int initTest() {
    Process p = Process(getpid());

    printf("initTest\tSUCCESS\n\n");
    return 0;
}

int testCore() {
    Process p = Process(getpid());
    p.generateCore();

    printf("CoreTest\tSUCCESS\n\n");
    return 0;
}

int sysTest() {
    //Sys s = Sys();
    //s.setTotalTime();
    printf("Total sys cpu time: %lu\n\n", Sys::getTotalTime());
}
