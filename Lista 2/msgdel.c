#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 

key_t key; 
int mqid;

#define EXTERNAL_MQ_ID 10002


void main()
{
	key = EXTERNAL_MQ_ID;	
	mqid = msgget(key, 0777);
	if (mqid == -1) {
   		printf("msgget falhou\n"); 
		exit(1); 
	} 
	printf("msgget OK, retornou id: %d\n", mqid);
	msgctl(mqid,IPC_RMID,NULL);
	printf("executou msgctl a fila de mensagens foi deletada\n");
	exit(0);	
}
