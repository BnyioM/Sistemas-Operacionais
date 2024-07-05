#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void fork_exemplo(char * argv[]);

int main(int argc, char * argv[]) {
    fork_exemplo(argv);
    return 0;
}

void fork_exemplo(char * argv[]) {
    int id;
    int32_t A;
    FILE* arq;

    id = fork();

    if (id == 0) {// Processo filho devido ao retorno zero
        arq = fopen(argv[0], "r"); 
        A = fscanf(arq, "%d", &A);
        fclose(arq);
        printf("Fork Filho: %d\n", A);
    }
    // Processo pai porque o retorno é diferente de zero
    else if (id > 0) {
        printf("Fork Pai: %d\n", A);
    }
}