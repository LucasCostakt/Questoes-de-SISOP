#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[]) 
{
	char texto[1024];

	if (argc<2)	
		return -1;
	gets(texto);
	printf("%d\n",strcmp(texto,argv[1]));
	return 0;
}

