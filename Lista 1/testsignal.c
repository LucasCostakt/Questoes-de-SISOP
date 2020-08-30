#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
 
void sigproc(int signum);
 
void quitproc(int signum); 
 
void main()
{
	signal(SIGINT, sigproc);
	signal(SIGQUIT, quitproc);
	printf("ctrl-c desabilitado use ctrl-\\ para sair\n");
	for(;;);
}
 
void sigproc(int signum)
{ 		 
	signal(SIGINT, sigproc); 
 	printf("voce usou o ctrl-c \n");
}
 
void quitproc(int signum)
{ 		 
	printf("ctrl-\\ use para sair\n");
	exit(0); 
}
