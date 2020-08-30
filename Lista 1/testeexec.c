#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{ 
	printf("Os arquivos do diretorio sao:\n");
	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	execl("/bin/ls", "ls", "-l", (char *) 0);
	printf("Depois do exec() o processo atual morre e nada mais é executado\n");
	printf("----------------------------------------------------------------\n");
	return 0;
}
