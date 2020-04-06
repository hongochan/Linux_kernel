#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX_COUNT 200
#define BUF_SIZE 100
char mess1[100]= "Parent writing!!!";
char mess2[100]= "Child writing!!!";
int main()
{
/*	pid_t pid;
	int i;
	char buf[BUF_SIZE];
	fork();
	pid=getpid();
	for(i=1;i<MAX_COUNT;i++)
	{
		sprintf(buf ,"This line from pid %d value = %d\n",pid,i);
		write(1,buf,strlen(buf));
	}

*/
	pid_t pid;
	pid=fork();
	char buf[100];
	int fd;
	if(pid>0)
	{
		/*
		printf("I'm a parent\n");
		write(fd,mess1,sizeof(mess1));
		fd = open("file.txt",O_RDWR | O_CREAT);*/
		sprintf(buf,"I'm parent\n");
		write(1,buf,strlen(buf));
	}
	else 
	{
		sprintf(buf,"I'm a child\n");
		write(1,buf,strlen(buf));
			
		/*fd = open("file.txt",O_RDWR | O_CREAT);
			printf("I'm a child\n");
			write(fd,mess1,sizeof(mess1));
*/
	}

	
	return 0;
}
