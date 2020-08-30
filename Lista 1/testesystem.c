#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{ 
	printf("Os arquivos do diretorio sao os seguintes:\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	system("ls -l");
	printf("Depois do system() o processo atual continua executando normalmente\n");
	printf("------------------------------------------------------------------\n");
	return 0;
}
