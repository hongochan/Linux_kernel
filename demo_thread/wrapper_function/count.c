#include "count.h"
#include <pthread.h>

int count;
pthread_mutex_t count_lock;
void count_increase()
{
	pthread_mutex_lock(&count_lock);
	count++;
	pthread_mutex_unlock(&count_lock);

}
void count_init()
{
	pthread_mutex_init(&count_lock,NULL);
}
