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
int iteracoes = 10000;

int main(int argc, char **argv) {
    int n = atoi(argv[1]);
	pid_t pid = 1;
	/*Exemplo de como criar n filhos*/
    for(int i = 0; i < n; i++) 
        if (pid != 0) 
            pid = fork();

	/*NÃO ALTERE ESSE PRINTF*/
	printf("Acc Esperado [%d] Acc obtido [%d]\n", n*iteracoes, acc);
    return 0;
}