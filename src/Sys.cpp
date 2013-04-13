#include "Sys.h"

#include <unistd.h>
#include <stdio.h>

// Set process directory
char *Sys::procdir = "/proc";

Sys::Sys()
{
    // Set system config
    this->pageSize = sysconf(_SC_PAGE_SIZE) / 1024;
    this->btime = this->parseBTime();
}

unsigned long int Sys::parseBTime() {
    FILE *procfd;
    char procfile[80];

    snprintf(procfile, sizeof procfile, "%s/stat",
            Sys::procdir);

    procfd = fopen(procfile, "r");
    if (procfd == NULL) {
        fprintf(stderr, "fopen error: %s\n", procfile);
        return -1;
    }

    char buf[256];
    fgets(buf, 256, procfd);
    fgets(buf, 256, procfd);
    fgets(buf, 256, procfd);
    fgets(buf, 256, procfd);
    fgets(buf, 256, procfd);
    fgets(buf, 256, procfd);

    unsigned long int time;
    sscanf(buf, "btime %lu", &time);
    fclose(procfd);
    return time;
}
