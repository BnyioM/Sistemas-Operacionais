/* g++ 2.cpp -pthread*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <semaphore.h>

int acc = 0;
int iteracoes = 10000;

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
	pid_t pid = 1;

    int* acc = (int*) mmap(NULL, sizeof (int) , PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    sem_t* semaphore = (sem_t*) mmap(NULL, sizeof (sem_t) , PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    sem_init(semaphore, 1, 1);
    
	/*Exemplo de como criar n filhos*/
    for(int i = 0; i < n - 1; i++) 
        if (pid != 0) 
            pid = fork();

	int j = 0;
	for (int i=0; i<iteracoes; i++){
		j ++;
	}
	sem_wait(semaphore);
	*acc = *acc + j;
	sem_post(semaphore);
    if(pid == 0)
        exit(EXIT_SUCCESS);

	/*NÃO ALTERE ESSE PRINTF*/
	printf("Acc Esperado [%d] Acc obtido [%d]\n", n*iteracoes, acc);
    return 0;
}