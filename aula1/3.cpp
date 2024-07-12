/*
gcc -pthread ... 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <chrono>
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

	// Execução por threads
	for(int t = 0; t < n_threads; t++ )
		pthread_create(&threads[t], NULL, worker, NULL);

	auto begin = std::chrono::high_resolution_clock::now();

	for( int i = 0; i < n_threads; i++ )
		pthread_join(threads[i], NULL);

	auto end = std::chrono::high_resolution_clock::now();

	auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	printf("Tempo decorrido de execução das threads: %f\n", elapsed.count() * 1e-9);

	// Execução sequencial

	begin = std::chrono::high_resolution_clock::now();

	for(int t = 0; t < n_threads; t++ )
		worker(NULL);

	end = std::chrono::high_resolution_clock::now();

	elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

	printf("Tempo decorrido de execução sequencial: %f\n", elapsed.count() * 1e-9);

	return 0;
}