#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int main (int argc, char *argv[]) 
{
	float valor_expoente;
	float valor_lido;

	if (argc==2)	{
		valor_expoente = atoi(argv[1]);
		scanf("%f",&valor_lido);
		printf("%f\n",powf(valor_lido, valor_expoente));
		return 0;	
	}

	if (argc==3) 
		if (strcmp(argv[1],"-c")==0) {
			valor_expoente = atoi(argv[2]);
			for(;;) {
				scanf("%f",&valor_lido);
				printf("%f\n",powf(valor_lido,valor_expoente));
				fflush(stdout);
			}
		}
	return -1;
}

