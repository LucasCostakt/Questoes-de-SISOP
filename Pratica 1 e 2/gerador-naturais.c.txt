#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main()
{
char dado[1024];
unsigned long n;
printf("Programa de Geracao de Naturais\n");
n=0;
for (;;) {
	printf("%lu\n",n);
	n++;
	sleep(1);
	}
}

