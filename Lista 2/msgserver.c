#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <ctype.h>

#define REQ_QUEUE 	10010
#define RESP_QUEUE 	10020

#define TO_UPPERCASE 1
#define TO_LOWERCASE 2

#define MAX_TEXT_SIZE 	1000

struct reqmsg {
	long	cli_id;
    	int	conv_type;
	char	textbuffer[MAX_TEXT_SIZE+1];
};

struct respmsg {
	long	cli_id;
    	char	textbuffer[MAX_TEXT_SIZE+1];
};

void stroupper(char * str) 
{
  
  	while (*str) {
    		*str = toupper((unsigned char) *str);
    		str++;
  	}

}

void strolower(char * str) 
{
  	
  	while (*str) {
    		*str = tolower((unsigned char) *str);
    		str++;
  	}

}

void main()
{
	int req_mq;
	int resp_mq;
	struct reqmsg cli_reqmsg;
	struct respmsg serv_respmsg;
	
	req_mq = msgget(REQ_QUEUE, IPC_CREAT | 0777);
	if (req_mq == -1) {
   		printf("msgget falhou no servidor\n"); 
		exit(1); 
	} 
	resp_mq = msgget(RESP_QUEUE, IPC_CREAT | 0777);
	if (resp_mq == -1) {
   		printf("msgget falhou no servidor\n"); 
		exit(1); 
	} 
	printf("servidor: iniciou execucao\n");
	for (;;) {
		
		if (msgrcv(req_mq,&cli_reqmsg,sizeof(struct reqmsg),0,0)<0) {
			printf("msgrcv falhou no servidor\n");
			exit(1);
		}
		printf("servidor: recebeu requisicao do cliente %ld\n",cli_reqmsg.cli_id);
		
		if (cli_reqmsg.conv_type==TO_UPPERCASE)
			stroupper(cli_reqmsg.textbuffer);
		else
			strolower(cli_reqmsg.textbuffer);
		
		serv_respmsg.cli_id = cli_reqmsg.cli_id;
		
		strcpy(serv_respmsg.textbuffer,cli_reqmsg.textbuffer);
	
		msgsnd(resp_mq,&serv_respmsg,sizeof(struct respmsg),0);
		printf("servidor: enviou resposta ao cliente %ld\n",serv_respmsg.cli_id);
	}

	exit(0);	
}
