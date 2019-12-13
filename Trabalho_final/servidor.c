#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <ctype.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <sys/socket.h>

#define _XOPEN_SOURCE_EXTENDED 1
#define REQ_QUEUE 	10010
#define RESP_QUEUE 	10020
#define MAX_TEXT_SIZE 	1000

char concat[MAX_TEXT_SIZE+1];
int  posUser=0;
int  users[MAX_TEXT_SIZE+1];

struct reqmsg {
 	long cli_id;
	char resposta_cli[MAX_TEXT_SIZE+1];   
	char comando[MAX_TEXT_SIZE+1];
	char path [MAX_TEXT_SIZE+1];	
	char caminho [MAX_TEXT_SIZE+1];
	char texto_msg[MAX_TEXT_SIZE+1];	
	long id_destino;
	char aux[MAX_TEXT_SIZE+1];
	long cod_mansgem;
	long id_pid;
	char remetente[8];
};

struct respmsg {
	long cli_id;
	char resposta[MAX_TEXT_SIZE+1];
	char caminho[MAX_TEXT_SIZE+1];
};
char * ls(char path[100]){
		memset (&concat, 0, sizeof (concat) );struct passwd *pw;struct group *gp;DIR *mydir;char *c;int i,linhaLs;
		struct dirent *myfile;struct stat fileStat;mydir=opendir(path);stat(".",&fileStat);

 	 while((myfile=readdir(mydir))!=NULL){
		char stat1[MAX_TEXT_SIZE+1],stat2[MAX_TEXT_SIZE+1],stat3[MAX_TEXT_SIZE+1],stat4[MAX_TEXT_SIZE+1],stat5[MAX_TEXT_SIZE+1],stat6[MAX_TEXT_SIZE+1],stat7[MAX_TEXT_SIZE+1],stat8[MAX_TEXT_SIZE+1],stat9[MAX_TEXT_SIZE+1],stat10[MAX_TEXT_SIZE+1],stat11[MAX_TEXT_SIZE+1];
			if(strcmp(myfile->d_name,".") != 0 && strcmp(myfile->d_name,"..") != 0){
			    stat(myfile->d_name,&fileStat); strcpy(stat1,(S_ISDIR(fileStat.st_mode)) ? "d" : "-");
			    strcpy(stat2,(fileStat.st_mode & S_IRUSR) ? "r" : "-");strcpy(stat3,(fileStat.st_mode & S_IWUSR) ? "w" : "-");
			    strcpy(stat4,(fileStat.st_mode & S_IXUSR) ? "x" : "-");strcpy(stat5,(fileStat.st_mode & S_IRGRP) ? "r" : "-");
			    strcpy(stat6,(fileStat.st_mode & S_IWGRP) ? "w" : "-");strcpy(stat7,(fileStat.st_mode & S_IXGRP) ? "x" : "-");
			    strcpy(stat8,(fileStat.st_mode & S_IROTH) ? "r" : "-");strcpy(stat9,(fileStat.st_mode & S_IWOTH) ? "w" : "-");
			    strcpy(stat10,(fileStat.st_mode & S_IXOTH) ? "x" : "-");pw=getpwuid(fileStat.st_uid);gp=getgrgid(fileStat.st_gid);strcat(concat,stat1);
				strcat(concat,stat2);strcat(concat,stat3);strcat(concat,stat4);strcat(concat,stat5);strcat(concat,stat6);strcat(concat,stat7);
				strcat(concat,stat8);strcat(concat,stat9);strcat(concat,stat10);strcat(concat," ");strcat(concat,gp->gr_name);strcat(concat," ");
				strcat(concat,pw->pw_name);strcat(concat," ");strcat(concat,myfile->d_name);strcat(concat,"\n");}}closedir(mydir);return concat;}

long int id_usuario(char init[8]){char atual;long count=0;int i = 0;
for (i; i < strlen(init); i++)
{if (init[i]=='a'){count = count + 250;}else if (init[i]=='b'){count = count + 575;}else if (init[i]=='c'){count = count + 20;}else if (init[i]=='d')
{count = count + 95;}else if (init[i]=='e'){count = count + 43;}else if (init[i]=='f'){count = count + 81;}else if (init[i]=='g'){count = count + 888;}
else if (init[i]=='h'){count = count + 5;}else if (init[i]=='i'){count = count + 34;}else if (init[i]=='j'){count = count + 475;}else if (init[i]=='k'){
count = count + 121;}else if (init[i]=='l'){count = count + 1221;}else if (init[i]=='m'){count = count + 632;}else if (init[i]=='n'){count = count + 864;
}else if (init[i]=='o'){count = count + 999;}else if (init[i]=='p'){count = count + 666;}else if (init[i]=='q'){count = count + 4123;}else if (init[i]=='r'){
count = count + 71;}else if (init[i]=='s'){count = count + 562;}else if (init[i]=='t'){count = count + 324;}else if (init[i]=='u'){count = count + 101;
}else if (init[i]=='v'){count = count + 21;}else if (init[i]=='x'){count = count + 17;}else if (init[i]=='z'){count = count + 13;}else if (init[i]=='0'){
count = count + 2019;}else if (init[i]=='1'){count = count + 45;}else if (init[i]=='2'){count = count + 12;}else if (init[i]=='3'){count = count + 751;
}else if (init[i]=='4'){count = count + 2101;}else if (init[i]=='5'){count = count + 1111;}else if (init[i]=='6'){count = count + 777;}else if (init[i]=='7')
{count = count + 642;}else if (init[i]=='8'){count = count + 314;}else if (init[i]=='9'){count = count + 210;}else{count = count +0;}
}return count;}

//Função da thread, thread que executa o comando 
void *printMsg(struct reqmsg *cli_reqmsg) {

		char str1[MAX_TEXT_SIZE+1];char newString[10][10];int i=0,j,ctr;char init[8];		       
			strcpy(str1,&cli_reqmsg->comando);j=0; ctr=0;
		    while(i<=(strlen(str1))){if(str1[i]==' '||str1[i]=='\0'){
			newString[ctr][j]='\0';ctr++;j=0;}else{newString[ctr][j]=str1[i];j++;}i++;}
		strcpy(&cli_reqmsg->comando,newString[0]);
		
		if(strcmp(cli_reqmsg->comando,"dirlist")==0||strcmp(cli_reqmsg->comando,"DIRLIST")==0){
			char *teste = ls(cli_reqmsg->path);	strcpy(cli_reqmsg->resposta_cli,teste);}
		else if(strcmp(cli_reqmsg->comando,"myid")==0|| strcmp(cli_reqmsg->comando,"MYID")==0){
			 long x = cli_reqmsg->cli_id;sprintf(cli_reqmsg->resposta_cli, "\n~ %s : Seu id é: %ld", cli_reqmsg->path, x);}
		else if(strcmp(cli_reqmsg->comando,"godir")==0||strcmp(cli_reqmsg->comando,"GODIR")==0){ 
			strcpy(cli_reqmsg->resposta_cli,cli_reqmsg->comando);
			strcpy(cli_reqmsg->aux,newString[1]);}			
		else if(strcmp(cli_reqmsg->comando,"exit")==0 || strcmp(cli_reqmsg->comando,"EXIT")==0){ 
			int i;for(i=0;i<10;i++){if(users[i]==cli_reqmsg->cli_id){users[i]=0;}	
			}strcpy(cli_reqmsg->resposta_cli, "Cliente deslogado");kill(cli_reqmsg->id_pid, SIGINT);}
		else if(strcmp(cli_reqmsg->comando,"help")==0||strcmp(cli_reqmsg->comando,"HELP")==0){ 
			strcpy(cli_reqmsg->resposta_cli,"DIRLIST: Lista os diretórios\nMYID: Mostra seu ID\nGODIR: Vai para o diretório desejado\nRUN: Roda a aplicação\nEXIT: Faz o logoff\nMAIL: Envia a mensagem de e-mail\nSHOWMAIL: Mostra todas as mensagens de e-mails recebidas\nSEND: Envia uma mensagem direta ao usuário destino\nRECEIVE: Retira e mostra na tela uma mensagem (se houver) da fila de mensagens\nUSERS: Mostra na tela a lista de usuários correntemente logados no sistema\nCLEAR: Limpa a tela\n");}
		else if(strcmp(cli_reqmsg->comando,"run")==0||strcmp(cli_reqmsg->comando,"RUN")==0){ 
			char resp[MAX_TEXT_SIZE+1];
			sprintf(resp, " gnome-terminal -e ./%s", newString[1]);
			sprintf(cli_reqmsg->resposta_cli,"\n~ %s : Executado com sucesso!!\n", cli_reqmsg->path);
			system(resp);}
		else if(strcmp(cli_reqmsg->comando,"mail")==0||strcmp(cli_reqmsg->comando,"MAIL")==0){ 	
			sprintf(cli_reqmsg->resposta_cli,"\n~ %s: Mensagem enviada!!\n", cli_reqmsg->path);
			strcpy(init,newString[1]);
			cli_reqmsg->id_destino = id_usuario(init);
			//strcpy(&cli_reqmsg->remetente,newString[1]);
			strcpy(&cli_reqmsg->texto_msg,newString[2]);
			for(i=3;i < ctr;i++){
			strcat(&cli_reqmsg->texto_msg," ");
			strcat(&cli_reqmsg->texto_msg,newString[i]);}}
		else if(strcmp(cli_reqmsg->comando,"showmail")==0||strcmp(cli_reqmsg->comando,"SHOWMAIL")==0){}
		else if(strcmp(cli_reqmsg->comando,"send")==0||strcmp(cli_reqmsg->comando,"SEND")==0){ 
			int login=0;
			int i;
			strcpy(init,newString[1]);
			cli_reqmsg->id_destino = id_usuario(init);

			for(i=0;i<MAX_TEXT_SIZE+1;i++)
			{if(users[i]==cli_reqmsg->id_destino){
					sprintf(cli_reqmsg->resposta_cli,"\n~ %s: Mensagem enviada!!\n", cli_reqmsg->path);
					login=1;
					cli_reqmsg->cod_mansgem=atol(newString[2]);
					strcpy(&cli_reqmsg->texto_msg,newString[3]);
					for(i=4;i < ctr;i++){
					strcat(&cli_reqmsg->texto_msg," ");
					strcat(&cli_reqmsg->texto_msg,newString[i]);break;}}}
			if(login==0){strcpy(cli_reqmsg->comando,"");
				sprintf(cli_reqmsg->resposta_cli,"\n~ %s: Mensagem não pode ser enviada usuário não está logado!!\n", cli_reqmsg->path);}}
		else if(strcmp(cli_reqmsg->comando,"receive")==0||strcmp(cli_reqmsg->comando,"RECEIVE")==0){}
		else if(strcmp(cli_reqmsg->comando,"login")==0||strcmp(cli_reqmsg->comando,"LOGIN")==0){
			int login=0;int i;for(i=0;i<10;i++){ 
				if(users[i]==cli_reqmsg->cli_id){
					strcpy(cli_reqmsg->resposta_cli,"O usuário ja esta logado!!\n");
					login=1;break;}}
			if(login==0){users[posUser] = cli_reqmsg->cli_id;
				sprintf(cli_reqmsg->resposta_cli,"\n~ %s: Logado seu id é %ld\n", cli_reqmsg->path, cli_reqmsg->cli_id);posUser++;}}

		else if(strcmp(cli_reqmsg->comando,"users")==0||strcmp(cli_reqmsg->comando,"USERS")==0){ 
			int i=0;char usersLogados[MAX_TEXT_SIZE+1];char concatena[MAX_TEXT_SIZE+1];strcpy(concatena,"Id dos Usuários logados agora: \n");
			for(i=0;i<10;i++){ if(users[i]!=0){
					snprintf( usersLogados, MAX_TEXT_SIZE+1 , "%d", users[i] );
					strcat(concatena,usersLogados);
					strcat(concatena,"\n");}}
			strcpy(cli_reqmsg->resposta_cli,"");
			strcpy(cli_reqmsg->resposta_cli,concatena);
			memset (&concatena, 0, sizeof (concatena));
		}else{sprintf(cli_reqmsg->resposta_cli,"~ %s : Comando não encontrado!!\n", cli_reqmsg->path);}}

void main(){
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
			pthread_t thread;
			pthread_create(&thread, NULL, (void *)printMsg, &cli_reqmsg);
			pthread_join(thread, NULL);	

		serv_respmsg.cli_id = cli_reqmsg.cli_id;

		strcpy(serv_respmsg.resposta,cli_reqmsg.resposta_cli);
		if (strcmp(cli_reqmsg.comando,"godir")==0||(cli_reqmsg.comando,"GODIR")==0){strcpy(serv_respmsg.caminho,cli_reqmsg.aux);}
		msgsnd(resp_mq,&serv_respmsg,sizeof(struct respmsg),0);
		printf("servidor: enviou resposta ao cliente %ld\n",serv_respmsg.cli_id);
	

	if (strcmp(cli_reqmsg.comando,"send")==0||(cli_reqmsg.comando,"SEND")==0||strcmp(cli_reqmsg.comando,"mail")==0||strcmp(cli_reqmsg.comando,"MAIL")==0)
	{
		char teste[MAX_TEXT_SIZE+1];
		sprintf(teste,"\n~ %s: Remetente %s, a mensagem é: %s\n", cli_reqmsg.path, cli_reqmsg.remetente, cli_reqmsg.texto_msg);
		serv_respmsg.cli_id = cli_reqmsg.id_destino;
		strcpy(serv_respmsg.resposta,teste);
		msgsnd(resp_mq,&serv_respmsg,sizeof(struct respmsg),0);
	}
	}
	exit(0);}

