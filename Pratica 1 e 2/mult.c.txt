#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char *argv[]) 
{
	float valor_multiplicado;
	float valor_lido;

	if (argc==2)	{
		valor_multiplicado = atoi(argv[1]);
		scanf("%f",&valor_lido);
		printf("%f\n",valor_lido * valor_multiplicado);
		return 0;	
	}

	if (argc==3) 
		if (strcmp(argv[1],"-c")==0) {
			valor_multiplicado = atoi(argv[2]);
			for(;;) {
				scanf("%f",&valor_lido);
				printf("%f\n",valor_lido * valor_multiplicado);
				fflush(stdout);
			}
		}
	return -1;
}

