#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("We are in prac-2b.c\n");
    printf("PID of prac-2b.c = %d\n", getpid());
    printf("%s", argv[0]);
    return 0;
}