/********************************
Kyle Halek
CPE 3600 - Dr. Rothe Section 131
Lab 9 - System calls
finfo.c: uses system calls from sys/stat to manipulate files instead of library functions
**********************************/

#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sched.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
First, locate and skim the man pages for file i/o via the system calls
open, read, write, etc. Note that they operate with an integer “file descriptor”
 as opposed to a FILE * used by the libc counterparts. What other major differences
 do you observe?
ANSWER: These system calls interact directly with the kernel.
*/

int main(int argc, char *argv[])
{
    /* The type of file - print this in a user readable way (typing man 2 stat gives this info)
    struct stat {
    //           dev_t     st_dev;          ID of device containing file 
    //           ino_t     st_ino;          Inode number 
    //           mode_t    st_mode;         File type and mode 
    //           nlink_t   st_nlink;        Number of hard links 
    //           uid_t     st_uid;          User ID of owner 
    //           gid_t     st_gid;          Group ID of owner 
    //           dev_t     st_rdev;         Device ID (if special file) 
    //           off_t     st_size;         Total size, in bytes 
    //           blksize_t st_blksize;      Block size for filesystem I/O 
    //           blkcnt_t  st_blocks;       Number of 512B blocks allocated */

    if (argc != 2)
    {
        printf("need 2 arguments\n");
        return 1;
    }
    // If here, have 2 args, 2nd should be file
    char *file = argv[1];
    struct stat daFile;

    if (stat(file, &daFile) != -1) {
        printf("File type: "); 

        if (S_ISREG(daFile.st_mode)) {
            printf("This file is a regular file\n");
        } else if (S_ISDIR(daFile.st_mode)) {
            printf("This is a directory file");
        } else if (S_ISLNK(daFile.st_mode)) {
            printf("Symbolic link file\n");
        } else if (S_ISFIFO(daFile.st_mode)) {
            printf("FIFO or Named Pipe file\n");
        } else if (S_ISCHR(daFile.st_mode)) {
            printf("Character Device file\n");
        } else if (S_ISBLK(daFile.st_mode)) {
            printf("This is a block device file\n");
        } else if (S_ISSOCK(daFile.st_mode)) {
            printf("Socket type\n");
        } else {
            printf("Unknown file Type\n");
        }
    } else {
        printf("File does not exist, provide existing file\n");
        return 0;
    }
    // The permissions set on the file - print these in a user readable way
    // If false, will print -
    printf("Permissions: ");
    printf((daFile.st_mode & S_IRUSR) ? "r" : "-");
    printf((daFile.st_mode & S_IWUSR) ? "w" : "-");
    printf((daFile.st_mode & S_IXUSR) ? "x" : "-");
    printf((daFile.st_mode & S_IRGRP) ? "r" : "-");
    printf((daFile.st_mode & S_IWGRP) ? "w" : "-");
    printf((daFile.st_mode & S_IXGRP) ? "x" : "-");
    printf((daFile.st_mode & S_IROTH) ? "r" : "-");
    printf((daFile.st_mode & S_IWOTH) ? "w" : "-");
    printf((daFile.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    // The owner of the file - printing the user identifier (number) is enough
    printf("file owner: %d\n", daFile.st_uid);

    // The size of the file IN BYTES
    printf("File size in bytes: %ld\n", daFile.st_size);

    // The date and time of last modification (format this for easy viewing, do NOT print out raw bytes or a large integer).
    struct tm *tm_info = localtime(&daFile.st_mtime); // mtime is modification time
    char date[20]; 
    strftime(date, 20, "%y-%m-%d", tm_info);
    printf("Last time modified: %s\n", date); 

    // If at any point, there is an error print an error and exit.
    return 0;
}
