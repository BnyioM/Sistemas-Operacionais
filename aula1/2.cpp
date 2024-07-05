/*
gcc -pthread ... 
*/

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <pthread.h>

#define NUM_THREADS 2

int number = -1;
bool number_has_changed = false;
const char* filename;

void* manipulate_file(void*);
void* wait_for_number(void*);

int main(int argc, char * argv[])
{
	filename = argv[1];

    pthread_t threads[NUM_THREADS];
    pthread_create(&threads[0], NULL, manipulate_file, NULL);
    pthread_create(&threads[1], NULL, wait_for_number, NULL);

    for (int i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);
    
    return 0;
}

void* manipulate_file(void*) {
    std::ifstream file;
    file.open(filename);

    if (!file.is_open())
        exit(EXIT_FAILURE);
    
    file >> number;
    file.close();
    number_has_changed = true;
    printf("Thread B: %d\n", number);
}

void* wait_for_number(void*) {
    while(1) {
        if (number_has_changed) {
            printf("Thread A: %d\n", number);
            break;
        }
    }
}