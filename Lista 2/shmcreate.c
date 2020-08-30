#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 

key_t key; 
int shmid; 

#define EXTERNAL_SHM_ID 10001
#define SHM_SIZE 100

char *psh_data;

void main()
{
	key = EXTERNAL_SHM_ID;	
	shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0777);
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
	printf("shmat vai colocar dados da memoria compartilhada\n");
	strcpy(psh_data,"texto com menos de 100 caracteres\n");
	printf("vai desconectar a memoria compartilhada (shdt)\n");
	shmdt(psh_data);
	exit(0);	
}
