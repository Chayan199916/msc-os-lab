#include<stdio.h>
#include<unistd.h>
//#include<sys/types.h>
#include<stdlib.h>
#include<sys/errno.h>
#include<sys/wait.h>

int main(int argc, char *argv[]){

    pid_t pid;
    int n, i, status;
    
    pid = fork();

    if (pid == -1)
    {
        
        perror("Fork call fails");
        exit(errno);
        
    }else /*parent and child process handling*/
    {

        wait(&status);
        printf("Enter the value of n : ");
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            printf("%d", i);

    }

}