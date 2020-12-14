#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
#include<fcntl.h>
#include <sys/errno.h>

void createFile(int argc, char *argv[])
{

    int fd, msg;
    char read_byte;
    fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_EXCL, 0777);
    if (fd != -1)
    {

        write(STDOUT_FILENO, "Enter the content of the file:\n", 31);

        while (read(STDIN_FILENO, &read_byte, sizeof(read_byte)) > 0)
        {

            if (read_byte == 'q')
                break;

            write(fd, &read_byte, sizeof(read_byte));
        }
        write(STDOUT_FILENO, "File Creation Done.\n", 20);
        close(fd);
    }
    else
    {

        write(STDOUT_FILENO, &errno, sizeof(errno));
        perror("File Open Error");
        exit(errno);
    }
}
void displayFile(int argc, char *argv[])
{
    int fd;
    char read_byte;
    fd = open(argv[argc - 1], O_RDONLY);
    if (fd != -1)
    {

        write(STDOUT_FILENO, "Data reading starts...\n", 23);

        while (read(fd, &read_byte, sizeof(read_byte)) > 0)
        {

            write(STDOUT_FILENO, &read_byte, sizeof(read_byte));
        }

        write(STDOUT_FILENO, "\nData reading done.\n", 20);
    }
    else if (fd == -1)
        fd = open(argv[1], O_CREAT, 0777);
    close(fd);
}
int main(int argc, char *argv[])
{
    pid_t pid_1, pid_2;
    //char *args[] = {argv[1], NULL};
    int status;

    pid_1 = fork();

    if(pid_1 == 0) /* child process 1 which creates file*/{

        printf("Entered in child process 1. pid : %d ppid : %d\n", getpid(), getppid());
        createFile(argc, argv);

    }
    else if(pid_1 > 0) /* within parent process, creates child process 2*/
    {
        
        wait(&status);
        printf("Returned in parent process. pid : %d ppid : %d child-process 1 id : %d\n", getpid(), getppid(), pid_1);
        
        pid_2 = fork();

        if(pid_2 == 0) /* child process 2 which displays file*/{

            printf("Entered in child process 2. pid : %d ppid : %d\n", getpid(), getppid());
            displayFile(argc, argv);

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
    return 0;
}
