/*
gcc -pthread ... 
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>
#include <iostream>

int iteracoes = 1000;

void worker(){
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
	return 0;
}