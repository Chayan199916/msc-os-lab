/* Program: fork.c -- A simple fork
 Shows PID, PPID in both parent and child */
#include <stdio.h>
#include <sys/types.h>
#include<unistd.h> /*warning: implicit declaration of function ‘fork’ [-Wimplicit-function-declaration]*/
#include <stdlib.h>

int main(void)
{
    pid_t pid;

    printf("Before fork\n");
    pid = fork(); /* Replicate current process */

    if (pid > 0)
    {             /* In the parent process; make sure */
        sleep(1); /* that parent doesn’t die before child */
        printf("PARENT-- PID: % d PPID: % d, CHILD PID: % d\n",getpid(), getppid(), pid);
    }
    else if (pid == 0) /*In the child process */
        printf("CHILD-- PID: % d PPID: % d\n", getpid(), getppid());

    else
    { /* pid must be -1 here */
        printf("Fork error \n");
        exit(1);
    }

    printf("Both processes continue from here\n"); /*In both processes */
    exit(0);
}