#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char name[16];
	char msg[64];
}thread_args;
static void *printHello(void *args)
{
	thread_args *thr_args = (thread_args*)args;
	printf("Hello World. I'm a %s\n",thr_args->name);
	printf("%s\n",thr_args->msg);
	pthread_exit(NULL);

}
int main()
{
	pthread_t threadID;
	int ret;
	thread_args thr;

	memset(&thr,0x0,sizeof(thread_args));
	strncpy(thr.name,"vimtor",sizeof(thr.name));
	strncpy(thr.msg,"I'm a new thread",sizeof(thr.msg));
       ret=pthread_create(&threadID,NULL,printHello,(&thr));
       if(ret)
       {
	       printf("Error can create thread %d\n",ret);
	       return -1;
       }
	pthread_exit(NULL);

}
