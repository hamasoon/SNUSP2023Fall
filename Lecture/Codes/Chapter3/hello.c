#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<assert.h>

#define BUFSIZE 50

int main(int argc, char *argv[])
{
    if(argc < 2) 
    {
	fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
	return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_RDONLY);
    ssize_t size;
    if(fd == -1) {
    	fprintf(stderr, "Fail to open file");
		  return EXIT_FAILURE;
    }

    char *c = (char*)malloc(sizeof(char) * BUFSIZE);

    printf("open file(%s) at fd(%d)\n", argv[1], fd);

    while((size = read(fd, c, sizeof(char) * BUFSIZE)) > 0) {
    	write(STDIN_FILENO, c, size);
    }

    close(fd);
    free(c);

    return EXIT_SUCCESS;
}
