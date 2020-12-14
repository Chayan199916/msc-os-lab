#include <stdio.h>
#include <sys/types.h>
#include<wait.h>
#include<unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include<sys/errno.h>

void show_content(){
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        printf("\nContent of the current directory goes here...");
        while ((dir = readdir(d)) != NULL)
        {
            printf("\n%s", dir->d_name);
        }
        closedir(d);
    }
}

int main(int argc, char *argv[])
{
    
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        printf("\n Entered in child...");
        show_content();
        printf("\n child finishes execution...");

    }else if (pid > 0)
    {
        wait(&status);
        printf("\nEntered in parent...");
        printf("\nParent process finishes execution...");
    }else
    {
        perror("Fork Open failed");
        exit(errno);
    }
    return 0;
}
