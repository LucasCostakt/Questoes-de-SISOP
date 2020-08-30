#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <unistd.h>


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


void main()
{
	int req_mq;
	int resp_mq;
	struct reqmsg cli_reqmsg;
	struct respmsg serv_respmsg;
	long cli_id;
	int optconv;

	cli_id = getpid();
	req_mq = msgget(REQ_QUEUE, 0777);
	if (req_mq == -1) {
   		printf("msgget falhou no cliente\n"); 
		exit(1); 
	} 
	resp_mq = msgget(RESP_QUEUE, 0777);
	if (resp_mq == -1) {
   		printf("msgget falhou no cliente\n"); 
		exit(1); 
	} 
	do  	{
		fflush(stdin);
		fflush(stdout);
		printf("Entre com o texto a ser convertido:\n");
		scanf("%[^\n]s",cli_reqmsg.textbuffer);
		printf("Qual opcao? 1 - Maiuscula; 2 - Minuscula; 9 - Finalizar programa\n");
		scanf("%d",&optconv);
		scanf("%*c");
		cli_reqmsg.conv_type=TO_UPPERCASE;
		if (optconv==1)
			cli_reqmsg.conv_type=TO_UPPERCASE;
		else if (optconv==2)
			cli_reqmsg.conv_type=TO_LOWERCASE;
		if (optconv!=9) {
			
			cli_reqmsg.cli_id = cli_id;
		
			msgsnd(req_mq,&cli_reqmsg,sizeof(struct reqmsg),0);
	
			if (msgrcv(resp_mq,&serv_respmsg,sizeof(struct respmsg),cli_id,0) < 0) {
				printf("msgrcv falhou no cliente\n");
				exit(1);
			}

			printf("O texto convertido e':\n");
			printf("%s\n",serv_respmsg.textbuffer);
		}
	} while(optconv!=9);
			

	exit(0);	
}
