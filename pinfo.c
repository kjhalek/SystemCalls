/********************************
Kyle Halek
CPE 3600 - Dr. Rothe Section 131
Lab 9 - System calls
pinfo.c: retrives process information and changes process priority
**********************************/
#define _GNU_SOURCE
#include "pinfo.h"
/*
 getpid()  returns  the process ID (PID) of the calling process.
   (This is often used by routines that generate unique temporary filenames.)

 The scheduling priority of the process, process group, or user, as indicated
    by which and who is obtained with the getpriority() call and set with the setpriority() call.
    The process attribute dealt with by these  system calls is the same attribute
    (also known as the "nice" value) that is dealt with by nice(2).

 The sched_setscheduler() system call sets both the scheduling policy and parameters for the thread
    whose ID is specified in pid.  If pid equals zero, the scheduling policy and parameters of the
     calling thread will be set.

The getcpu() system call identifies the processor and node  on  which
       the  calling  thread  or process is currently running and writes them
       into the integers pointed to by the cpu and node arguments.  The pro‐
       cessor  is  a  unique small integer identifying a CPU.  The node is a
       unique small identifier identifying a NUMA node.  When either cpu  or
       node is NULL nothing is written to the respective pointer.

 getrusage() returns resource usage measures for who, which can be one
       of the following: RUSAGE_SELF, CHILDREN, THREAD

The  getrlimit()  and  setrlimit()  system calls get and set resource
       limits.  Each resource has an associated soft and hard limit, as  de‐
       fined by the rlimit structure
*/

int main(int argc, char *argv[])
{

    // Take a single command line parameter that is a PID (So only 2 args):
    if (argc != 2)
    {
        int pid = getpid();
        printf("Current pid: %d\n", pid);
        return 1;
    }

    // Correct argument amount: 2
    int PID = atoi(argv[1]);
    if (PID <= 0)
    {
        // Process identifier does not exist, print error:
        fprintf(stderr, "This PID does not exist: %s\n", argv[1]);
        return 1;
    }
    printf("PID: %d\n", PID);

    // If we are here, PID is a valid process. Get process priority:
    //PRIO_PROCESS (which) retrieves the scheduled priority of PID (who)
    int priority = getpriority(PRIO_PROCESS, PID);
    if (priority != -1) {
        printf("Process priority: %d\n", priority);
    } else {
        printf("Error with priority, exiting\n");
        return 1;
    }





    // Get scheduling method as a string

    int policy = sched_getscheduler(PID);
    //Policy will now have SCHED_"METHOD" where "METHOD" is type.
    // Can break this down within a switch to get string data with macros given in sched.h file
    char* schedMethod;
    switch(policy) {
        case SCHED_OTHER:
        schedMethod = "SCHED_OTHER";
        break;
        case SCHED_BATCH:
        schedMethod = "SCHED_BATCH";
        break;
        case SCHED_IDLE:
        schedMethod = "SCHED_IDLE";
        break;
        case SCHED_FIFO:
        schedMethod = "SCHED_FIFO";
        break;
        case SCHED_RR:
        schedMethod = "SCHED_RR";
        break;
    }
    printf("Scheduling method: %s\n", schedMethod);

    return 0;

}
