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

int main(int argc, char * argv[])
{
    int id;
    int var;
    int* number = (int*) mmap(NULL, sizeof (int) , PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    *number = -1;
    const char* filename = argv[1];
    
    return 0;
}
