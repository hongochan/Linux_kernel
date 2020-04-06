#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

void main()
{
	int shm_fd;
	const  char* message_0 = "Hello World\n ";
	void* ptr;
	shm_fd = shm_open("hello_c", O_CREAT | O_RDWR,0666);
	ftruncate(shm_fd,4096);
	ptr = mmap(0,4096,PROT_WRITE,MAP_SHARED,shm_fd,0);
	strcpy(ptr,message_0);
	return;

}


