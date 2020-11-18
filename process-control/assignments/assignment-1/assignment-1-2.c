#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/errno.h>

int main(){

    pid_t pid;
    int process_img_chng_check;
    char *args[] = {"elephant", "dog", "cat", "deer", NULL};

    printf("Before calling fork() system call\n");

    pid = fork();

    if(pid == 0){

        printf("Entered in child process. pid : %d ppid : %d\n", getpid(), getppid());
        process_img_chng_check = execv("./assignment-1-1", args);
        if(process_img_chng_check == -1){

            perror("Failed to replace process image\n");
            exit(errno);

        }

    }
    else if(pid == -1){

        perror("Failed to create child process\n");
        exit(errno);

    }
    else
    {
        sleep(1);
        printf("Entered in parent process. pid : %d ppid : %d child-process id : %d\n", getpid(), getppid(), pid);

    }
    
}