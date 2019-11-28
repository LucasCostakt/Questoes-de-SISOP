#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int nfilho;
void proc_filho(int valor){
    nfilho = valor;
    printf("Processo FILHO %d iniciado\n", nfilho);
    printf("Vai dormir por %d segundos\n", nfilho*10);
    sleep(nfilho*10);
    printf("Processo FILHO %d encerrado\n", nfilho);
    
    
}


int main(int argc, char *argv[])
{
    int i;
   for(i=4;i>0;i--)
    { 
        if(fork() == 0) 
        { 
            //printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
            proc_filho(i);
            exit(0); 
        } else if(i == 4){
            printf("Processo pai iniciado\n");
        }
    } 
    for(i=1;i<5;i++)
    wait(NULL); 
return 0;
}

