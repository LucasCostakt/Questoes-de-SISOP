#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <unistd.h>


#define REQ_QUEUE 	10010
#define RESP_QUEUE 	10020


#define MAX_TEXT_SIZE 	1000

//Struct para enviar
struct reqmsg {
 	long cli_id;
   	int	tempoSleepThread;
    char msgInicial[MAX_TEXT_SIZE+1];
    char msgFinal[MAX_TEXT_SIZE+1];
	char nomeThread[MAX_TEXT_SIZE+1];
};

//Struct para receber
struct respmsg {
	long cli_id;
	char nomeThread[MAX_TEXT_SIZE+1];
};



void main()
{
    //Definição de variáveis
	int req_mq;
	int resp_mq;
	struct reqmsg cli_reqmsg;
	struct respmsg serv_respmsg;
	long cli_id;
    int tempo;
	
//Define o id para conexão
	cli_id = getpid();
	req_mq = msgget(REQ_QUEUE, 0777);

//Verificação se vai falhar a conexão
	if (req_mq == -1) {
   		printf("msgget falhou no cliente\n"); 
		exit(1); 
	} 
	resp_mq = msgget(RESP_QUEUE, 0777);
	if (resp_mq == -1) {
   		printf("msgget falhou no cliente\n"); 
		exit(1); 
	} 
	do {
        //Limpa
		fflush(stdin);
		fflush(stdout);

        //Define o nome da thread
		printf("Entre com o nome da thread:\n");
		scanf("%[^\n]s",cli_reqmsg.nomeThread);

        //Define o tempo de sleep da thread
		printf("Quanto tempo essa thread irá rodar?\n");
		scanf("%d",&tempo);
        scanf("%*c");
        cli_reqmsg.tempoSleepThread = tempo;

        //Define a mensagem inicial a ser exibida
        printf("Entre com a Mensagem de inicio da thread: \n");
		scanf("%[^\n]s",cli_reqmsg.msgInicial);
        scanf("%*c");

        //Define a mensagem final a ser exibida
        printf("Entre com a Mensagem Final da thread: \n");
		scanf("%[^\n]s",cli_reqmsg.msgFinal);
		scanf("%*c");

		if (1) {
			// Preenche o tipo da mensagem com o identificador (PID) do cliente
			cli_reqmsg.cli_id = cli_id;

			// Envia requisicao ao servidor
			msgsnd(req_mq,&cli_reqmsg,sizeof(struct reqmsg),0);
            
			// Espera pela mensagem de resposta especifica para este cliente
			// usando o PID do processo cliente como tipo de mensagem
			if (msgrcv(resp_mq,&serv_respmsg,sizeof(struct respmsg),cli_id,0) < 0) {
				printf("msgrcv falhou no cliente\n");
				exit(1);
			}
			// Apresenta o nome da thread e que ela finalizou de rodar no servidor
			printf("A Thread %s finalizou!!:\n", serv_respmsg.nomeThread);
		}
	} while(1);
			

	exit(0);	
}
