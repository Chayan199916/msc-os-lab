#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<wait.h>
#include<stdlib.h>
#include<sys/errno.h>

int main(int argc, char *argv[]){

    pid_t pid_1, pid_2;
    char *args[] = {argv[1], NULL};
    int status;

    pid_1 = fork();

    if(pid_1 == 0) /* child process 1 which creates file*/{

        printf("Entered in child process 1. pid : %d ppid : %d\n", getpid(), getppid());
        execv("./assignment-1-3-child-1", args);
        perror("Failed to replace child-1 process image\n");
        _exit(errno);

    }
    else if(pid_1 > 0) /* within parent process, creates child process 2*/
    {
        
        wait(&status);
        printf("Returned in parent process. pid : %d ppid : %d child-process 1 id : %d\n", getpid(), getppid(), pid_1);
        
        pid_2 = fork();

        if(pid_2 == 0) /* child process 2 which displays file*/{

            printf("Entered in child process 2. pid : %d ppid : %d\n", getpid(), getppid());
            execv("./assignment-1-3-child-2", args);
            perror("Failed to replace child-2 process image\n");
            _exit(errno);

        }
        else if(pid_2 > 0){

            wait(&status);
            printf("Returned in parent process. pid : %d ppid : %d child-process id : %d\n", getpid(), getppid(), pid_2);

        }
        else
        {
            perror("Fork Error in child 2 creation");
            exit(errno);
        }
        
    }
    else
    {
        perror("Fork Error in child 1 creation");
        exit(errno);
    }
    
}