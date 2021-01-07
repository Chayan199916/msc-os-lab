/*
C program to perform append operation using lseek system call
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/errno.h>

int main(int argc, char *argv[]){

    int fd;
    char read_byte;
    //char *content = (char *)calloc(buff_size, sizeof(char));
    fd = open(argv[1], O_WRONLY);
    if (fd != -1)
    {

        lseek(fd, 0, SEEK_END);
        while (read(STDIN_FILENO, &read_byte, sizeof(read_byte)) > 0)
        {
          
            write(fd, &read_byte, sizeof(read_byte));

        }
        close(fd);

    }else
    {
        
        perror("File Opening Failed");
        exit(errno);

    }
    
}
/*
after giving inputs, press 'q' then enter.
*/