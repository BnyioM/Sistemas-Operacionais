/*g++ 1.cpp*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int acc = 0;
int iteracoes = 10000;/*NÃO ALTERE ESSE VALOR*/
pthread_mutex_t mutex;

void* worker(void *thread_id){
	int j = 0;
	for (int i=0; i<iteracoes; i++){
		j ++;
	}
	pthread_mutex_lock(&mutex);
	acc = acc + j;
	pthread_mutex_unlock(&mutex);
}

int main(int argc, char * argv[]){
	int n_threads = atol(argv[1]);
	pthread_t threads[n_threads];
	pthread_mutex_init(&mutex, NULL);

	for(int t = 0; t < n_threads; t++ )
	      pthread_create(&threads[t], NULL, worker, (void *)t);

	for (int i = 0; i < n_threads; i++)
        pthread_join(threads[i], NULL);
    
	/*NAO ALTERE ESSE PRINTF*/
    printf("Acc Esperado [%d] Acc obtido [%d]\n", n_threads*iteracoes, acc);
	
	return 0;
}