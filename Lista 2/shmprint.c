#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 

key_t key; /* key to be passed to shmget() */ 
int shmid; /* return value from shmget() */ 

#define EXTERNAL_SHM_ID 10001
#define SHM_SIZE 100

char *psh_data;

void main()
{
	key = EXTERNAL_SHM_ID;	
	shmid = shmget(key, SHM_SIZE, 0777);
	if (shmid == -1) {
   		perror("shmget falhou"); 
		exit(1); 
	} 
	printf("shmget retornou id: %d\n", shmid);
	psh_data = shmat(shmid,NULL,0);
	if (psh_data == (char *) -1) {
   		perror("shmat falhou"); 
		exit(1); 
	}
	printf("shmat vai imprimir dados da memoria compartilhada\n");
	puts(psh_data);
	printf("vai desconectar a memoria compartilhada\n");
	shmdt(psh_data);
	exit(0);	
}
