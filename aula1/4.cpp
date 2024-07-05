/*
gcc -pthread ... 
*/

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
#include <pthread.h>

#define NUM_THREADS 3

int number = -1;
bool number_has_changed = false;
bool vector_is_populated = false;
std::vector<int> vet;

void* get_vector_size(void*);
void* populate_vector(void*);
void* show_vector_elements(void*);

int main(int argc, char * argv[])
{	
    pthread_t threads[NUM_THREADS];
    pthread_create(&threads[0], NULL, get_vector_size, NULL);
    pthread_create(&threads[1], NULL, populate_vector, NULL);
    pthread_create(&threads[2], NULL, show_vector_elements, NULL);

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);
    
    return 0;
}

void* get_vector_size(void*) {
    scanf("%d", &number);
    if (number <= 0)
        exit(EXIT_FAILURE);
    number_has_changed = true;
}
void* populate_vector(void*) {
    while(1) {
        if (number_has_changed) {
            vet.reserve(number);
            for (int i = 0; i < number; i++) {
                vet[i] = 1 + 2*i;
            }
            vector_is_populated = true;
            break;
        }
    }

}
void* show_vector_elements(void*) {
    while(1) {
        if (vector_is_populated) {
            for (int i = 0; i < number; i++)
                printf("Elemento do indice %d do vetor: %d\n", i, vet[i]);
            break;
        }
    }
}
