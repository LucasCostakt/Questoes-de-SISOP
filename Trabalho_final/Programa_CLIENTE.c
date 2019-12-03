#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <unistd.h>
#include <ctype.h>


#define REQ_QUEUE 	10010
#define RESP_QUEUE 	100200
#define MAX_TEXT_SIZE 	1000

//Struct para enviar
struct reqmsg {
 	long cli_id;
  	char nomeFuncao[MAX_TEXT_SIZE+1];
};

//Struct para receber
struct respmsg {
	long cli_id;
	char nomeFuncao[MAX_TEXT_SIZE+1];
};



void main()
{
    //Definição de variáveis
	int req_mq;
	int resp_mq;
	struct reqmsg cli_reqmsg;
	struct respmsg serv_respmsg;
	long cli_id;
	FILE *pont_arq;
	char usuario[MAX_TEXT_SIZE+1];
	long usuario_number;

do{

	printf("Já é usuário? digite S ou N:\n");
		scanf("%s",usuario);
		scanf("%*c");
//	*usuario = toupper((unsigned char) *usuario);

	if (strcmp(usuario, "N") == 0)
	{
		
		cli_id = getpid();
		printf("Seu id é: %li\n", cli_id);
		break;
	}else if(strcmp(usuario, "S") == 0){
		printf("Digite seu id:\n");
		scanf("%li", &usuario_number);
		cli_id = usuario_number;
		break;
	}
	printf("Erro digite novamente\n");
}while (1);


//Define o id para conexão
	
	req_mq = msgget(REQ_QUEUE, 0777);

//Verificação se vai falhar a conexão
	if (resp_mq == -1) {
   		printf("msgget falhou no cliente\n"); 
		exit(1); 
	} 

	do {
		do{
        //Limpa
		fflush(stdin);
		fflush(stdout);

        //Define o nome da funcao
		printf("Entre com a função:\n");
		scanf("%[^\n]s",cli_reqmsg.nomeFuncao);
        scanf("%*c");


		if (strcmp(cli_reqmsg.nomeFuncao,"RUN") == 0)
		{
			/* code */
		} 
		else if (strcmp(cli_reqmsg.nomeFuncao,"MAIL") == 0)
		{
			/* code */
		}
		else if (strcmp(cli_reqmsg.nomeFuncao,"SHOWMAIL")==0)
		{
			/* code */
		}else if (strcmp(cli_reqmsg.nomeFuncao,"SEND")==0)
		{
			/* code */
		}else if (strcmp(cli_reqmsg.nomeFuncao,"RECEIVE") == 0)
		{
			/* code */
		}else if (strcmp(cli_reqmsg.nomeFuncao,"USERS")==0)
		{
			/* code */
		}else if (strcmp(cli_reqmsg.nomeFuncao,"MYID")==0)
		{
			/* code */
		}else if (strcmp(cli_reqmsg.nomeFuncao,"DIRLIST")==0)
		{
			/* code */
		}else if (strcmp(cli_reqmsg.nomeFuncao,"GODIR")==0)
		{
			/* code */
		}else if (strcmp(cli_reqmsg.nomeFuncao,"EXIT")==0)
		{
			
		}else{
			printf("Função não existente\n");
		}
	}while(1);

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
			printf("A resposta do precesso é: \n %s \n", serv_respmsg.nomeFuncao);

	} while(1);
			

	exit(0);	
}
