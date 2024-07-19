/* g++ 2.cpp -pthread*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>

int acc = 0; 
int* number = (int*) mmap(NULL, sizeof (int) , PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);
int iteracoes = 10000;
pthread_mutex_t* mutex = (pthread_mutex_t*) mmap(NULL, sizeof (pthread_mutex_t) , PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
    *number = 0;
	pid_t pid = 1;
	/*Exemplo de como criar n filhos*/
    for(int i = 0; i < n; i++) 
        if (pid != 0) 
            pid = fork();

    if (pid == 0) {
        int j = 0;
        for (int i=0; i<iteracoes; i++){
            j ++;
        }
        pthread_mutex_lock(mutex);
        *number = *number + j;
        pthread_mutex_unlock(mutex);
    } else if (pid > 0) {

        for (int i = 0; i < n; i++) {
            wait(NULL); // Aguarda todos os processos-filho
        }

        acc = *number;
        /*NÃO ALTERE ESSE PRINTF*/
        printf("Acc Esperado [%d] Acc obtido [%d]\n", n*iteracoes, acc);
    }
    return 0;
}