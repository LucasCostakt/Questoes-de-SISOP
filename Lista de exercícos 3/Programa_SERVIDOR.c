#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <ctype.h>
#include <pthread.h>


#define REQ_QUEUE 	10010
#define RESP_QUEUE 	10020

#define TO_UPPERCASE 1
#define TO_LOWERCASE 2

#define MAX_TEXT_SIZE 	1000

//Struct para receber
struct reqmsg {
 	long cli_id;
   	int	tempoSleepThread;
    char msgInicial[MAX_TEXT_SIZE+1];
    char msgFinal[MAX_TEXT_SIZE+1];
	char nomeThread[MAX_TEXT_SIZE+1];
};
//Struct para enviar
struct respmsg {
	long cli_id;
	char nomeThread[MAX_TEXT_SIZE+1];
};
//Função da thread, é um ponteiro que recebe os valores atribuidos da struct e mostra na tela do servidor
void *printMsg(struct reqmsg *cli_reqmsg) {
	printf("%s\n", cli_reqmsg->msgInicial);
	printf("Esta thread vai rodar por %d segundos.\n", cli_reqmsg->tempoSleepThread);
	sleep(cli_reqmsg->tempoSleepThread);
	printf("%s\n", cli_reqmsg->msgFinal);

}


void main()
{
	//Definição de variáveis
	int req_mq;
	int resp_mq;
	struct reqmsg cli_reqmsg;
	struct respmsg serv_respmsg;
	
	//Verificação se vai falhar a conexão
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
		// Espera pela requisicao de qualquer cliente (message type=0)
		if (msgrcv(req_mq,&cli_reqmsg,sizeof(struct reqmsg),0,0)<0) {
			printf("msgrcv falhou no servidor\n");
			exit(1);
		}

		printf("servidor: recebeu requisicao do cliente %ld\n",cli_reqmsg.cli_id);
		
		
		// Cria a thread requerida
			printf("criando nova thread %s \n", cli_reqmsg.nomeThread);
			pthread_t thread;
			pthread_create(&thread, NULL, (void *)printMsg, &cli_reqmsg);
			pthread_join(thread, NULL);	


		// Copia o identificador do cliente para a mensagem de resposta
		serv_respmsg.cli_id = cli_reqmsg.cli_id;

		// Copia o nome para a mensagem de resposta
		strcpy(serv_respmsg.nomeThread,cli_reqmsg.nomeThread);

		// Envia a resposta ao cliente
		msgsnd(resp_mq,&serv_respmsg,sizeof(struct respmsg),0);
		printf("servidor: enviou resposta ao cliente %ld\n",serv_respmsg.cli_id);
	}

	exit(0);	
}

