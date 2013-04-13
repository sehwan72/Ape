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
    this->btime = this->parseBTime();

    this->version = (char *) malloc (512);
    this->parseVersion(&this->version, 512);
}

Sys::~Sys() {
    free(this->version);
}

unsigned long int Sys::parseBTime() 
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
