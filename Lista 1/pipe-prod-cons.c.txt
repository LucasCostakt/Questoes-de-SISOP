#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{
	int pdes[2];
	pid_t pid;
	char txt_parent[100];
 	char txt_child[100]; 
	pipe(pdes);
	pid = fork();
	if ( pid>0 ) { /* parent process - producer */
		close(pdes[0]); 
		strcpy(txt_parent,"olah tudo bem?\n");
		write( pdes[1], txt_parent, 100); /* write to child */
		wait(NULL);
		close(pdes[1]);
	} else if (pid==0) {/* child process - consumer */ 		
		close(pdes[1]); 
		read( pdes[0], txt_child, 100); /* read from parent */
		printf("O filho leu:\n");
		printf("%s",txt_child);
		close(pdes[0]);
	} else {
		exit(-1);
	}
	exit(0);
}

