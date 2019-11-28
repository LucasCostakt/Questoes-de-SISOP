#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();
    fork();

    printf("Estou vivo!\n");
    sleep(20);
    
return 0;
}