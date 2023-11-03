/********************************
Kyle Halek
CPE 3600 - Dr. Rothe Section 131
Lab 9 - System calls
pmod.c: this file uses system calls to delay a system process while other processes
    are active. This sleeps the pmod call when called by the specified
    nanosecond time to exemplify the process.
**********************************/

#include "pmod.h"


/*
Nice: used to adjust the priority of processes
nanosleep: prevents program execution for a period of time based off user preference.
    Basically delays a process
*/
int main() {

/*
Modifies its own priority to REDUCE it by 10 
 - NOTE Make sure you specify the correct number to REDUCE the priority not increase.
Niceness  values
       range from -20 (most favorable to the process) to 19 (least favorable
       to the process).
*/
    nice(10);
   
//Sleeps for 1,837,272,638 nano seconds
    struct timespec delay;
    delay.tv_nsec = 837272638;
    nanosleep(&delay, NULL);

//Prints a goodbye message and exits
    printf("BYE!\n");
    return 0;

}