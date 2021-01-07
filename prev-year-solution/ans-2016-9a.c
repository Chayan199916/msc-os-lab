#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>
#include<sys/errno.h>

int main(){
    pid_t pid;
    int barrier;
    char *args[] = {"wc", "-w", "ans-2016-6b.c", (char *) 0};
    pid = fork();
    if(pid == 0){ /*child process*/
        printf("Enters in child process\n");
        execv("/bin/wc", args);
        perror("Execv error : wc image replacement failed");
        _exit(errno);
    }
    else if (pid > 0) /*returns to parent*/
    {
        wait(&barrier);
        printf("Inside parent process : returns from child\n");
    }
    else
    {
        perror("Fork error : child process creation failed");
        exit(errno);
    }
}