#include <stdio.h>
#include <pthread.h>
#include <string.h>
int count;
pthread_mutex_t count_lock;
void *my_thread(void *args)
{
	int i=0;
	pthread_mutex_lock(&count_lock);
	for(i=0;i<50000;i++)
		count++;
	pthread_mutex_unlock(&count_lock);
	return NULL;
}
void main()
{
	pthread_t thread1,thread2;
	char a[100] = { 0 };
	memset(a, 0, sizeof(a));
	pthread_mutex_init(&count_lock,NULL);

	pthread_create(&thread1,NULL,my_thread,"Han");
	pthread_create(&thread2,NULL,my_thread,"Ngoc");
	
	
	pthread_join(thread1,(void *)&a);
	pthread_join(thread2,(void *)&a);
	printf("Count = %d",count);
	pthread_mutex_destroy(&count_lock);
}
