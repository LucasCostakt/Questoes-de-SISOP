#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
char dado[1024];

printf("Programa de Registro de Dados Universal\n");
for (;;) {
	printf("Entre com o dado a ser registrador:\n");
	gets(dado);
	if (strcmp(dado,"fim")==0)
		break;
}
}

