#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h> // for opening
#include<errno.h>
#include<unistd.h> // for closing
extern int errno;

int main(){
	int fd1, fd2;
	//fd1 = creat("Create.txt", 0777);
	fd2 = open("Creat.txt", O_RDONLY|O_CREAT);
	if(fd1 == -1 || fd2 == -1){
		printf("error no. : %d\n",errno);
		perror("Program");
	}
	printf("%d\t%d", fd1, fd2);
	close(fd1);
	close(fd2);
	return 0;
}
