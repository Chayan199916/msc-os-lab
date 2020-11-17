/*
C program to insert content in the middle of the file.
*/
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/errno.h>

int main(int argc, char *argv[]){

    int fd, size;
    char read_byte;
    fd = open(argv[1], O_WRONLY);
    if(fd != -1){

        size = lseek(fd, 0, SEEK_END);
        lseek(fd, (size / 2), SEEK_SET);
        while (read(STDIN_FILENO, &read_byte, sizeof(read_byte)) > 0)
        {
            
            write(fd, &read_byte, sizeof(read_byte));

        }
        close(fd);

    }else
    {
        perror("File Opening failed");
        exit(errno);
    }

}