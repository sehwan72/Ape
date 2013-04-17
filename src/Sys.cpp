#include "Sys.h"

#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <string>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

// Set process directory
char *Sys::procdir = "/proc";

Sys::Sys()
{
    // Set system config
    this->pageSize   = sysconf(_SC_PAGE_SIZE) / 1024;
   // this->childMax   = sysconf(_SC_CHILD_MAX);
   // this->clockTicks = sysconf(_SC_CLK_TCK);
   // this->openMax    = sysconf(_SC_OPEN_MAX); // max open files
   // this->streamMax  = sysconf(_SC_STREAM_MAX);
    this->btime = this->updateStat();

    this->version = (char *) malloc (512);
    this->parseVersion(&this->version, 512);
    this->totalCPU = 0;
}

Sys::~Sys() {
    free(this->version);
}

unsigned long int Sys::updateStat()
{
    FILE *procfd;
    char procfile[80];

    snprintf(procfile, sizeof procfile, "%s/stat",
            Sys::procdir);

    procfd = fopen(procfile, "r");
    if (procfd == NULL) {
        fprintf(stderr, "fopen error: %s\n", procfile);
        return -1;
    }

    int bufSize = 1024 * 1000;
    char buf[bufSize];
    fgets(buf, bufSize, procfd);
    fgets(buf, bufSize, procfd);
    fgets(buf, bufSize, procfd);
    fgets(buf, bufSize, procfd);
    fgets(buf, bufSize, procfd);
    fgets(buf, bufSize, procfd);
    fgets(buf, bufSize, procfd);
    fgets(buf, bufSize, procfd);

    unsigned long int time;
    sscanf(buf, "btime %lu", &time);

    fgets(buf, bufSize, procfd);
    fgets(buf, bufSize, procfd);
    sscanf(buf, "procs_running %lu", &this->runningProcesses);
    fgets(buf, bufSize, procfd);
    sscanf(buf, "procs_blocked %lu", &this->blockedProcesses);

    fclose(procfd);
    return time;
}

int Sys::parseVersion(char **buffer, int buf_size)
{
    char verpath[20];
    int fd;

    snprintf(verpath, sizeof verpath, "%s/version", 
            Sys::procdir);

    fd = open(verpath, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "open error: %s", verpath);
        return -1;
    }

    bzero(*buffer, buf_size);
    read(fd, *buffer, buf_size);
    close(fd);
}
