#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>          
#include <sys/types.h>
#include <sys/stat.h>        
#include <semaphore.h>


int main()
{
	sem_t *pnewsem;
	
	pnewsem = sem_open("/meu_semaforo",O_CREAT,0777,10);
	if (pnewsem == SEM_FAILED) {
   		printf("semaforo open falhou\n"); 
		exit(1); 
	} 
	printf("semaforo criado\n");
	printf("vai fechar o semaforo\n");

	sem_close(pnewsem);

	exit(0);
	return 0;	
}
