#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZ 50

int main(int argc, char *argv[]) {
	int fd, target;
	ssize_t len, w_len = 0;
	const char CUR_DIR[] = ".";
	char dir_path[BUF_SIZ], buf[BUF_SIZ];

	if (argc < 2) {
		strcpy(dir_path, CUR_DIR);
	}
	else {
		strcpy(dir_path, argv[1]);
	}

	if((fd = open(dir_path, O_RDONLY) < 0)) {
		printf(STDERR_FILENO, "Can't open file(%s)", dir_path);
		return EXIT_FAILURE;
	}

	if((target = open("copy.txt", O_RDWR)) < 0) {
		
	}

	while((len = read(fd, buf, BUF_SIZ)) > 0) {
		while(len - w_len > 0) {
			if((w_len = write(target, buf, len)) > 0) {
				len -= w_len;
			}
			else {
				perror("write error");
				return EXIT_FAILURE;
			}
		}
	}
}
