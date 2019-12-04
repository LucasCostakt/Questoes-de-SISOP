#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	pid_t child_pid;
	pid_t parent_pid;
	int child_status;

	pid = fork();
	if (pid<0) {
		printf("Erro no fork()\n");
		exit(-1);
	} else if (pid==0) {
		child_pid = getpid();
		printf("Eu sou o processo filho, com pid=%d\n",child_pid);
		exit(0);
	} else {
		parent_pid = getpid();
		printf("Eu sou o proceso pai, com pid=%d\n",parent_pid);
		wait(&child_status);
		printf("O processo filho retornou: %d\n",child_status);
		exit(0);
	}
	return 0;
}

