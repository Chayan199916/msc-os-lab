#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv){

	int fd;
	char read_byte;
	fd = open(argv[argc - 1], O_RDONLY);
	if(fd!= -1){

        write(STDOUT_FILENO, "Data reading starts...\n", 23);

		while(read(fd, &read_byte, sizeof(read_byte)) > 0){

			write(STDOUT_FILENO, &read_byte, sizeof(read_byte));

		}

        write(STDOUT_FILENO, "\nData reading done.\n", 20);

	}
	else if(fd == -1)
		fd = open(argv[1], O_CREAT, 0777);
	close(fd);
	exit(1);

}
