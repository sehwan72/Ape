#include <stdio.h>
#include "../src/Process.h"
#include "../src/Sys.h"

int initTest();
int sendSignal();
int sysTest();

int main()
{
    initTest();
    sysTest();
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

int sysTest() {
    Sys s = Sys();
    s.setTotalTime();
    printf("Total sys cpu time: %lu\n", s.getTotalTime());
}
