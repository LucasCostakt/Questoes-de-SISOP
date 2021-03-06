#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 

key_t key; 
int mqid; 

#define EXTERNAL_MQ_ID 10002


char msgbuf[100];


void main()
{
	key = EXTERNAL_MQ_ID;	
	mqid = msgget(key, IPC_CREAT | 0777);
	if (mqid == -1) {
   		printf("msgget falhou\n"); 
		exit(1); 
	} 
	printf("msgget OK, retornou id: %d\n", mqid);
	printf("vai enviar duas mensagens para a fila\n");

	strcpy(msgbuf,"Esta e' a primeira mensagem a ser enviada\n");
	msgsnd(mqid,msgbuf,strlen(msgbuf)+1,0);

	strcpy(msgbuf,"'esta e' a segunda mensagem que sera' enviada\n");
	msgsnd(mqid,msgbuf,strlen(msgbuf)+1,0);

	exit(0);	
}
