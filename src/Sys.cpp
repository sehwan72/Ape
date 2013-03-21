#include "Sys.h"

#include <stdio.h>

// Set process directory
char *Sys::procdir = "/proc";

Sys::Sys(){}

int Sys::setTotalTime()
{
    FILE *statfd;
    char statfile[30];
    unsigned long int cputime[10];
    unsigned long int total = 0;

    snprintf(statfile, sizeof statfile, "%s/stat", Sys::procdir);
    
    statfd = fopen(statfile,"r");
    if (statfd == NULL) {
        perror("fopen error");
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

    this->totalTime = total;
    return 0;
}

unsigned long int Sys::getTotalTime()
{
    return this->totalTime;
}