#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARR_SIZE 1024*1024

char global[ARR_SIZE];

int main(int argc, char *argv[]) {
    char *ptr = malloc(ARR_SIZE);
    
    printf("Hello, world\n");

    printf("address of main:        %p\n", main);
    printf("address of printf:      %p\n", printf);
    printf("address of global:      %p\n", global);
    printf("address of ptr:         %p\n", &ptr);
    printf("address of mem[ptr]:    %p\n", ptr);

    while(1) sleep(1);

    return EXIT_SUCCESS;
}