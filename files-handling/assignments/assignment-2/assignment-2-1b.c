#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd, i, filesize = 0;
    char c[10] = "Bye World!", ch;

    fd = open("lseek-demo.txt", O_RDWR);

    for (i = 1; read(fd, &ch, 1); i++)
        filesize++;
    printf("The current filesize is: %d", filesize);

    lseek(fd, 0, SEEK_END);

    filesize = filesize + write(fd, c, sizeof(c));

    printf("\nThe filesize after appending is: %d\n", filesize);

    close(fd);

    return 0;
}