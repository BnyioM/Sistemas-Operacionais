/*
gcc -pthread ... 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <iostream>

void* worker(void*);

int iteracoes = 1000;

void* worker(void*){
	for (int i=0; i<iteracoes; i++){
		for (int j=0; j<iteracoes; j++){
			for (int k=0; k<iteracoes; k++){
					sqrt(i%100);
			}
		}
	}
}

int main(int argc, char * argv[]){
	int n_threads = atol(argv[1]);
	pthread_t threads[n_threads];

	for(int t = 0; t < n_threads; t++ )
		pthread_create(&threads[t], NULL, worker, (void *)t);

	for( int i = 0; i < n_threads; i++ )
		pthread_join(threads[i], NULL);

	return 0;
}