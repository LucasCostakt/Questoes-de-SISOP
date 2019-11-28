#include <stdio.h>
#include <pthread.h>
#include <math.h>


void *printMsg(char* msg) {
	int t = rand()%(20+1-5)+5;
	printf("esta thread vai dormir por %d segundos.\n", t);
	sleep(t);
	printf("esta thread acordou\n");
    printf("esta thread terminou\n");
	return NULL;
}

int main(int argc, char** argv) {

		int i;
        int valor;

        printf("Digite o número de threads desejado\n");
        scanf("%d", &valor);

		for(i=1;i<=valor;i++)
		{
			pthread_t thread;
			printf("criando nova thread %d \n",i);
			pthread_create(&thread, NULL, (void*)printMsg,"minhaThread ");
			pthread_join(thread, NULL);		
            
		}		
		printf("O programa Terminou");
		return 0;
}