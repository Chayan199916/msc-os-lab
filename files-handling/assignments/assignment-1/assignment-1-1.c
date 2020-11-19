/*
c program to create new text file by taking i/p s from kboard.
command line args and sys calls have to be used wherever possible.
*/
#include<stdio.h> // perror
#include <unistd.h> // read, write, close
#include <stdlib.h> // exit()
#include <fcntl.h> // mode consts
#include <signal.h> // SIGTSTP
#include <sys/errno.h> //errno

int main(int argc, char **argv)
{

	int fd, msg;
	char read_byte;
	fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_EXCL, 0777);
	if (fd != -1)
	{

		while (read(STDIN_FILENO, &read_byte, sizeof(read_byte)) != SIGTSTP)
		{

			write(fd, &read_byte, sizeof(read_byte));
		
		}
		close(fd);

	}
	else
	{
		
		write(STDOUT_FILENO, &errno, sizeof(errno));
		perror("File Open Error");
		exit(errno);

	}
	
}