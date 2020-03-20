#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("TEST\n");
	const char* s = getenv("PATH");
	printf("PATH %s\n",(s!=NULL)?s:"error");
	printf("Finished");
	return 0;
}
