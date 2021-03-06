#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <sys/wait.h>
#include <unistd.h>


#define EXTERNAL_SHM_ID 10003


struct myshm 
	{
	int	control_flag1;
	int	control_flag2;
	int	counter1;
	int	counter2;
	char	buffer1[500];
	char	buffer2[500];
	float	x;
	float	y;
	};

struct myshm *pmyshm;

int shmid; 

void main()
{
	pid_t pid;

	shmid = shmget(EXTERNAL_SHM_ID, sizeof(struct myshm), IPC_CREAT | 0777);
	if (shmid == -1) {
   		perror("shmget falhou"); 
		exit(1); 
	} 

	pmyshm = shmat(shmid,NULL,0);
	if (pmyshm == (struct myshm *) -1) {
   		perror("shmat falhou no pai"); 
		exit(1); 
	}
	pmyshm->control_flag1=0;

	pid = fork();
	if (pid>0) {
	// The FATHER PROCESS ... continues to use pmyshm without problem
		strcpy(pmyshm->buffer1,"Oi filho!\n");
		pmyshm->control_flag1=1;
		while(pmyshm->control_flag2==0);
		puts(pmyshm->buffer1);
		puts(pmyshm->buffer2);
		shmdt(pmyshm);
		shmctl(shmid,IPC_RMID,NULL);
	} else {
	// The SON OF THE FATHER PROCESS ... must shmat a new block of memory
		pmyshm = shmat(shmid,NULL,0);
		pmyshm->control_flag2=0;
		if (pmyshm == (struct myshm *) -1) {
   			perror("shmat falhou no filho"); 
			exit(1); 
		}
		while(pmyshm->control_flag1==0);
		printf("o proc pai escreve na flag \n");
		strcpy(pmyshm->buffer2,"meu pai!\n");
		pmyshm->control_flag2 = 1;
		shmdt(pmyshm);
	}
	exit(0);	
}
