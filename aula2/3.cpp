/*gcc -pthread 3.cpp*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <limits>

/*NÃO ALTERE ESSA VARIAVEL*/
int N = 0;

/*NAO ALTERE ESSE FUNCAO*/
void print_buffer(int i){
 for (int j = 0; j<i;j++) printf("#");
}

void* produtor(void *thread_id){
	while(1)
	{
	print_buffer(++N);//Funciona se trocarmos por N++?
	printf("\n");
	}
}

void* consumidor(void *thread_id){
	while(1){
	print_buffer(--N);//Funciona se trocarmos por N--?
	printf("\n");	
	}
}

int main(int argc, char * argv[]){
	int consumidores = atol(argv[1]);
	int produtores = atol(argv[2]);
	pthread_t threads[consumidores+produtores];
	for(int t = 0; t < produtores; t++)
		pthread_create(&threads[t], NULL, produtor, (void *)t);

	for (int t =0; t<consumidores;t++)
		pthread_create(&threads[t], NULL, consumidor, (void *)t);
	
	while(1);
	return 0;
}