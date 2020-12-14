#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int fd;
    char read_byte, input_pattern = 'a', output_pattern = '$';

    if (argc != 2)
    {

        write(STDOUT_FILENO, 'less arguments', 14);
        exit(0);
    }
    else
    {

        fd = open(argv[1], O_RDWR);
        if (fd != -1)
        {
            while (read(fd, &read_byte, 1) > 0)
            {
                if (read_byte == input_pattern)
                {
                    lseek(fd, -1, SEEK_CUR);
                    write(fd, &output_pattern, sizeof(output_pattern));
                }
                
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

    return 0;
}
