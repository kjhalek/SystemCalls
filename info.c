/********************************
Kyle Halek
CPE 3600 - Dr. Rothe Section 131
Lab 9 - System calls
info.c: retrieves information via system calls about the current running system (my PC).
**********************************/
#include "info.h"
#include <time.h>

int main() {
    struct timespec ts;

    //    init_array();
    //    control();
    if (clock_gettime(CLOCK_REALTIME, &ts) == 0)
    {
        printf("Current time in nanoseconds: %ld\n", ts.tv_nsec);
    }

    char hostname[_SC_HOST_NAME_MAX];
    if (gethostname(hostname, sizeof(hostname)) == 0)
    {
        printf("system network name: %s\n", hostname);
    }

    struct utsname info;

    if (uname(&info) == 0)
    {
        printf("Operating system name: %s\n", info.sysname);
        printf("Operating system release and version: %s\n", info.release);
        printf("System hardware type: %s\n", info.machine);
    }

    long numOfProcessors = get_nprocs();
    if (numOfProcessors > 0)
    {

        printf("Number of CPU's on the system: %ld\n", numOfProcessors);
    }

    long pagesize = sysconf(_SC_PAGESIZE);
    long total = sysconf(_SC_PHYS_PAGES) * pagesize;
    long free = sysconf(_SC_AVPHYS_PAGES) * pagesize;
    if (total > 0)
    {
        printf("Total amount of physical memory in bytes: %ld\n", total);
    }
    if (total > 0)
    {
        printf("Total amount of free memory in bytes: %ld\n", free);
    }
}


