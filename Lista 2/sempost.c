#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <fcntl.h>           
#include <sys/stat.h>        
#include <semaphore.h>


int main()
{
	sem_t *pnewsem;
	int n;
	
	pnewsem = sem_open("/meu_semaforo",0);
	if (pnewsem == SEM_FAILED) {
   		printf("semaforo open falhou\n"); 
		exit(1); 
	} 
	printf("obteve acesso ao semaforo\n");

	
	sem_post(pnewsem);
	sem_close(pnewsem);


	exit(0);
	return 0;	
}
