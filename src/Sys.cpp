#include "Sys.h"

#include <unistd.h>
#include <stdio.h>

// Set process directory
char *Sys::procdir = "/proc";

Sys::Sys()
{
    // Set system config
    this->pageSize = sysconf(_SC_PAGE_SIZE) / 1024;
}
