/*
c program to make a copy of the text file created in assignment-1-1.c.
system calls should be used.
*/
#include<fcntl.h>
#include<sys/errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int main(){

    int fd1, fd2, check_read;
    char read_byte;
    fd1 = open("new-file.txt", O_RDONLY);
    fd2 = open("new-file-copy.txt", O_WRONLY | O_CREAT | O_EXCL, 0777);
    if (fd1 == -1 || fd2 == -1)
    {
        
        write(1, &errno, sizeof(errno));
		perror("File Open Error");
		exit(1);

    }
    else
    {
        
        while (read(fd1, &read_byte, sizeof(read_byte)) > 0)
        {
            
            write(fd2, &read_byte, sizeof(read_byte));

        }
        close(fd1);
        close(fd2);

    }
    return 0;
    
}