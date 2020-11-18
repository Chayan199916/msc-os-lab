#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    printf("PID of prac-2a.c = %d\n", getpid());
    char *args[] = {"Hello", "C", "Programming", NULL};
    execv("./prac-2b", args);
    printf("Back to prac-2a.c");
    return 0;
}