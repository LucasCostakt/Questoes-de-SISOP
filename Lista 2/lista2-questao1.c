#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <sys/wait.h>
#include <unistd.h>
#include <ctype.h>


#define EXTERNAL_SHM_ID 10003

#define TO_UPPERCASE 1
#define TO_LOWERCASE 2

#define MAX_TEXT_SIZE 500


struct myshm 
	{
	int	control_flag1;
	int	control_flag2;
	int	convType;
	char	textbuffer[MAX_TEXT_SIZE+1];
	};

struct myshm *pmyshm;

int shmid; 

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

void father_proc()
{
	int optconv;


	printf("Entre com o texto a ser convertido:\n");
	fgets(pmyshm->textbuffer,MAX_TEXT_SIZE,stdin);
	fflush(stdin);
	printf("Qual opcao de conversao? 1 - Maiuscula; 2 - Minuscula\n");
	scanf("%d",&optconv);
	if (optconv==1)
		pmyshm->convType=TO_UPPERCASE;
	else if (optconv==2)
		pmyshm->convType=TO_LOWERCASE;
	else
		pmyshm->convType = TO_UPPERCASE;

	
	pmyshm->control_flag1=1;

	while(pmyshm->control_flag2==0);

	printf("O texto convertido e':\n");
	puts(pmyshm->textbuffer);


	shmdt(pmyshm);
	shmctl(shmid,IPC_RMID,NULL);
}

void child_proc()
{

 
	
	pmyshm = shmat(shmid,NULL,0);
	if (pmyshm == (struct myshm *) -1) {
   		perror("shmat falhou no processo filho"); 
		exit(1); 
	}

	while(pmyshm->control_flag1==0);
	printf("vai fazer conversao de tipo %d\n",pmyshm->convType);

	if (pmyshm->convType==TO_UPPERCASE)
		stroupper(pmyshm->textbuffer);
	else
		strolower(pmyshm->textbuffer);


	pmyshm->control_flag2 = 1;
	shmdt(pmyshm);
}
void main()
{
	pid_t pid;
	shmid = shmget(EXTERNAL_SHM_ID, sizeof(struct myshm), IPC_CREAT | 0777);
	if (shmid == -1) {
   		
		exit(1); 
	} 

	pmyshm = shmat(shmid,NULL,0);
	if (pmyshm == (struct myshm *) -1) {
   		
		exit(1); 
	}
	pmyshm->control_flag1=0;
	pmyshm->control_flag2=0;
		
	pid = fork();
	if (pid>0) {
		father_proc();
	} else {
		child_proc();
	}
	exit(0);	
}
