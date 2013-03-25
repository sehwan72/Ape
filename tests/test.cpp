#include <stdio.h>
#include "../src/Process.h"
#include "../src/Sys.h"

int initTest();
int sendSignal();
int sysTest();
int testCore();
int procStatTest();
int procCPUTest();

int main()
{
    initTest();
    sysTest();
    procStatTest();
    procCPUTest();
    //testCore();
    //sendSignal();
}

int procCPUTest()
{
    Process p = Process(1712);
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

    printf("initTest\tSUCCESS\n");
    return 0;
}

int testCore() {
    Process p = Process(getpid());
    p.generateCore();

    printf("CoreTest\tSUCCESS\n");
    return 0;
}

int sysTest() {
    //Sys s = Sys();
    //s.setTotalTime();
    printf("Total sys cpu time: %lu\n", Sys::getTotalTime());
}
