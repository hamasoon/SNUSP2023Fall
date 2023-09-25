#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 1024

const char INPUT_FILENAME[] = "target.txt";
const char OUTPUT_FILENAME[] = "overwrite.txt";

int main(int argc, char* argv[]) {
    char *target;

    if (argc < 2) {
        target = (char *)malloc(strlen(INPUT_FILENAME) + 1);
        strcpy(target, INPUT_FILENAME);
    }
    else {
        target = (char *)malloc(strlen(argv[1]) + 1);
        strcpy(target, argv[1]);
    }

    FILE *input_fptr = fopen(target, "rb");
    FILE *output_fptr = fopen(OUTPUT_FILENAME, "a"); // Changed "rw" to "wb"
    free(target);

    if (input_fptr == NULL || output_fptr == NULL) {
        perror("Error");
        return EXIT_FAILURE;
    }

    char buf[BUFSIZE];
    size_t size = 0;

    while ((size = fread(buf, sizeof(char), BUFSIZE, input_fptr)) > 0) {
        fwrite(buf, sizeof(char), size, output_fptr);
    }

    fclose(input_fptr);
    fclose(output_fptr);

    return EXIT_SUCCESS;
}
