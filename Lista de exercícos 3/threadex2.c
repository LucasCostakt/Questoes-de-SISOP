#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printMsg(char* msg) {
	int* pstatus = (int*)malloc(sizeof(int));	
	*pstatus = 123456;
	printf("%s\n", msg);
	pthread_exit(pstatus);
}

int main(int argc, char** argv) {
	pthread_t thrdID;
	int *pstatus;

	printf("criando nova thread\n");
	pthread_create(&thrdID, NULL, (void*)printMsg, argv[1]);
	printf("nova thread criada: %ld\n", thrdID);
	pthread_join(thrdID, (void *)&pstatus);
	printf("Thread %ld finalizou com status: %d\n",thrdID,*pstatus);	
	return 0;
}
