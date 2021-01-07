#include<stdio.h> // perror
#include <stdlib.h> // exit()
#include <fcntl.h> // pid_t defined here
#include <sys/errno.h> //errno
#include<time.h>
#include<assert.h>
#include<wait.h>
#include<unistd.h>

int main(){
    
    pid_t pid_1;
    pid_t pid_2;
    int barrier;
    time_t t = time(NULL);
    struct tm *tm;
    char s[64];
    printf("Inside parent process: before fork call\n");
    pid_1 = fork();
    if (pid_1 == 0) /*child 1*/
    {
        printf("Entered in first child process\n");
        printf("Process id of the first child process is : %d\n", getpid());
        printf("First child finishes execution\n");
    }
    else if (pid_1 > 0) /*returns to parent from child 1*/
    {
        wait(&barrier);
        printf("Inside parent process: after first child returns\n");
        pid_2 = fork();
        if (pid_2 == 0) /*child 2*/
        {
            printf("Entered in second child process\n");
            printf("Process id of the second child process is : %d\n", getpid());
            tm = localtime(&t);
            assert(strftime(s, sizeof(s), "%c", tm));
            printf("Inside second child process : Current sys date-time %s\n", s);
            printf("second child finishes execution\n");
        }
        else if (pid_2 > 0) /*returns to parent from child 2*/
        {
            wait(&barrier);
            printf("Inside parent process: after second child returns\n");
        }
        else
        {
            perror("Fork error in child 2 creation");
            exit(errno);
        }
    }
    else
    {
        perror("Fork error in child 1 creation");
        exit(errno);
    }
    return 0;
}