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
	exit(1);
}

/*
to quit and save the content, press 'q' and then enter
*/