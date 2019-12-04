#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main (int argc, char *argv[]) 
{
	float valor_dividido;
	float valor_lido;

	if (argc==2)	{
		valor_dividido = atoi(argv[1]);
		if (valor_dividido==0)
			return -1;
		scanf("%f",&valor_lido);
		printf("%f\n",valor_lido / valor_dividido);
		return 0;	
	}

	if (argc==3) 
		if (strcmp(argv[1],"-c")==0) {
			valor_dividido = atoi(argv[2]);
			if (valor_dividido==0)
				return -1;
			for(;;) {
				scanf("%f",&valor_lido);
				printf("%f\n",valor_lido / valor_dividido);
				fflush(stdout);
			}
		}
	return -1;
}

