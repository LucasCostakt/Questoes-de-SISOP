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
	if (sem_unlink("/meu_semaforo")==-1) {
		printf("semaforo unlink falhou\n"); 
		exit(1); 
	} 
	printf("deletou (unlink) o semaforo\n");
	exit(0);
	return 0;	
}
