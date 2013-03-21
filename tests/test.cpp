#include <stdio.h>
#include "../src/Process.h"
#include "../src/Sys.h"

int initTest();
int sendSignal();
int sysTest();
int testCore();

int main()
{
    initTest();
    sysTest();
    testCore();
    sendSignal();
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
    Sys s = Sys();
    s.setTotalTime();
    printf("Total sys cpu time: %lu\n", s.getTotalTime());
}
