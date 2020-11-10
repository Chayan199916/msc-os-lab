/*
c program to check whether the sizes of the two text files created by 
assignment-1-1.c and assignment-1-2.c are same or not.
*/
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/errno.h>
#include<stdlib.h>

int main(){

    int fd1, fd2, file_1_size = 0, file_2_size = 0;
    fd1 = open("new-file.txt", O_RDONLY);
    fd2 = open("new-file-copy.txt", O_RDONLY);
    char read_byte;
    if (fd1 == -1 || fd2 == -1)
    {
        
        write(1, &errno, sizeof(errno));
		perror("File Open Error");
		exit(1);

    }
    else
    {
        
        while (read(fd1, &read_byte, sizeof(read_byte)) > 0)
            file_1_size++;
        
        while (read(fd2, &read_byte, sizeof(read_byte)) > 0)
            file_2_size++;
        
        if (file_1_size == file_2_size)
            printf("They are of same sizes...");
        else
            printf("They are of different sizes...");
        
        close(fd1);
        close(fd2);
                
    }
    
}
