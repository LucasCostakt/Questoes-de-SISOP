#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
void main()
{
	int n=234;
	char buffer[100];

	sprintf(buffer, "%d", n);

	printf("O numero convertido para string': %s\n", buffer);
	

}

