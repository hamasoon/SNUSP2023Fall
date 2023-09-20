#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_CHARS 128
#define CHARS_PER_LINE 16

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        fprintf(stderr, "(use '-' for stdin)\n");
        return EXIT_FAILURE;
    }

    int fd, i, n;
    unsigned char c;

    if (strcmp(argv[1], "-") == 0) fd = stdin;
    else if((fd = open(argv[1], O_RDONLY)) == -1) {
        fprintf(stderr, "Cannot open file.");
        return EXIT_FAILURE;
    }

    n = DEFAULT_CHARS;
    if (argc >= 3) n = atoi(argv[2]);

    i = 0;
    printf("04%d: i");
    
    while (i < n) {
        int r = read(fd, &c, sizeof(c));
        if (r == sizeof(c)) {
            i++;
            
            if (c < 32) printf("<%02x>", c);
            else printf("%c", c);
            
            if (i % CHARS_PER_LINE == 0) {
                printf("\n");
                if (i < n) printf("%04d: ", i);
            }
        } else {
            fprintf(stderr, "\nError reading file (pos: %d).\n", i);
            break;
        }
    }
 
    if (i % CHARS_PER_LINE > 0) printf("\n");
 
    //
    // cleanup & return
    //
    close(fd);
 
    return EXIT_SUCCESS;
}