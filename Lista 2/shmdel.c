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
	shmid = shmget(key, SHM_SIZE, 0777);
	if (shmid == -1) {
   		perror("shmget falhou"); 
		exit(1); 
	} 
	printf("shmget retornou id: %d\n", shmid);
	shmctl(shmid,IPC_RMID,NULL);
	printf("executou shmctl segmento de memoria compartilhada foi deletado\n");
	exit(0);	
}
