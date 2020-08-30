#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{ 
	printf("Os processos sao os seguintes:\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	fork();
	system("ps aux");
	printf("Antes foi executado um fork(), o que sera' que vai acontecer?\n");
	printf("-------------------------------------------------------------\n");
	return 0;
}
