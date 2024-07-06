/*
gcc -pthread ... 
*/

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>

void* manipulate_file(const char* filename, int* number);

int main(int argc, char * argv[])
{
    int id;
    int var;
    int* number = (int*) mmap(NULL, sizeof (int) , PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    *number = -1;
    const char* filename = argv[1];

    id = fork();

    if (id == 0) {// Processo filho devido ao retorno zero
        manipulate_file(filename, number);
    }
    // Processo pai porque o retorno é diferente de zero
    else if (id > 0) {
        wait(NULL);
        printf("Processo Pai: %d\n", *number);
    }
    
    return 0;
}

void* manipulate_file(const char* filename, int* number) {
    std::ifstream file;
    file.open(filename);

    if (!file.is_open())
        exit(EXIT_FAILURE);
    
    file >> *number;
    file.close();
    printf("Processo Filho: %d\n", *number);
}