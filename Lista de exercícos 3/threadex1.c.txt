#include <stdio.h>
#include <pthread.h>

void *printMsg(char* msg) {
	printf("%s\n", msg);
	return NULL;
}

int main(int argc, char** argv) {
	pthread_t thrdID;
	printf("criando nova thread\n");
	pthread_create(&thrdID, NULL, (void*)printMsg, argv[1]);
	printf("nova thread criada: %ld\n", thrdID);
	pthread_join(thrdID, NULL);
	printf("a nova thread foi finalizada\n");
	return 0;
}
