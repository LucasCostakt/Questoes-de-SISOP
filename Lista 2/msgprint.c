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
int msgsize;

void main()
{
	key = EXTERNAL_MQ_ID;	
	mqid = msgget(key, 0777);
	if (mqid == -1) {
   		printf("msgget falhou\n"); 
		exit(1); 
	} 
	printf("shmget OK, retornou id: %d\n", mqid);
	printf("vai esperar e imprimir duas mensagens\n");

	msgsize = msgrcv(mqid,msgbuf,sizeof(msgbuf),0,0);
	if (msgsize<0) {
		printf("msgrcv falhou\n");
		exit(1);
	}
	printf("recebeu PRIMEIRA mensagem:\n");
	puts(msgbuf);

	msgsize = msgrcv(mqid,msgbuf,sizeof(msgbuf),0,0);
	if (msgsize<0) {
		printf("msgrcv falhou\n");
		exit(1);
	}
	printf("recebeu SEGUNDA mensagem:\n");
	puts(msgbuf);

	exit(0);	
}
