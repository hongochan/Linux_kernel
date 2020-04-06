#include <stdio.h>
#include <signal.h>
void my_sig_handler(int signo)
{
	printf("My signal handler call...Hello WOrld \n");
}	

void main()
{
	signal(SIGINT,my_sig_handler);
	while(1);

}
