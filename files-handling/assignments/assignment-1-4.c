/*
c program to display content of a file if it exists 
else create a new file of 0 length.
*/
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv){

	int fd;
	char read_byte;
	if(((fd = open(argv[1], O_RDONLY)) != -1)){

		while(read(fd, &read_byte, sizeof(read_byte)) > 0){

			write(STDOUT_FILENO, &read_byte, sizeof(read_byte));

		}

	}
	else if(fd == -1)
		fd = open(argv[1], O_CREAT, 0777);
	close(fd);
	return 0;

}
