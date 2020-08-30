#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{
	int pdes[2];
	pid_t pid;
	char txt_parent[100];
 	char txt_child[100]; 
	pipe(pdes);
	pid = fork();
		//Processo pai produtor 
	if ( pid>0 ) { 
		close(pdes[0]); 
		strcpy(txt_parent,"olá\n");
		// Escreve no filho 
		write( pdes[1], txt_parent, 100); 
		wait(NULL);
		close(pdes[1]);
		// Processo filho consumidor  		
	} else if (pid==0) {
		close(pdes[1]); 
		// le no pai 
		read( pdes[0], txt_child, 100); 
		printf("O filho leu:\n");
		printf("%s",txt_child);
		close(pdes[0]);
	} else {
		exit(-1);
	}
	exit(0);
}

