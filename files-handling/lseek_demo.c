#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/errno.h>
#include<stdlib.h>

int main(int argc, char **argv){

    int fd;
    char read_byte;
    fd = open(argv[1], O_RDONLY);
    if(fd != -1){

        lseek(fd, 0, SEEK_SET);
        while (read(fd, &read_byte, sizeof(read_byte)) > 0)
        {
            
            write(STDOUT_FILENO, &read_byte, sizeof(read_byte));

        }
        close(fd);

    }
    else
    {
        
        write(STDOUT_FILENO, &errno, sizeof(errno));
        perror("File Open");
        exit(0);

    }
    
}