#include <stdio.h>
#include "../src/Process.h"

int initTest();
int sendSignal();

int main()
{
    initTest();
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
