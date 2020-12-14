#include <dirent.h>
#include <stdio.h>
 
int main(void)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d)
    {
        printf("\nContent of the current directory goes here...");
        while ((dir = readdir(d)) != NULL)
        {
            printf("\n%s", dir->d_name);
        }
        closedir(d);
    }
    return(0);
}