//--------------------------------------------------------------------------------------------------
// M1522.000800 System Programming                                        Seoul National University
//
// Author: Bernhard Egger <bernhard@csap.snu.ac.kr>
// (C) Computer Systems and Platforms Laboratory, Seoul National University
//
// Hexdump with Unix I/O
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define DEFAULT_WIDTH 8
#define MAX_WIDTH 64

int hexdump(char *fn, int WIDTH);

int main(int argc, char **argv)
{
  int width = DEFAULT_WIDTH;

  // check that we got the correct number of arguments
  if ((argc < 2) || (argc > 3)) {
    printf("syntax: %s <filename> [<width>]\n", argv[0]);
    return EXIT_FAILURE;
  }

  // if the user specified a width, parse it and make
  // sure it's within the limits
  if (argc == 3) width = atoi(argv[2]);
  if (width < 1) width = 1;
  if (width > MAX_WIDTH) width = MAX_WIDTH;

  return hexdump(argv[1], width);
}

//
// hexdump(char *fn, int WIDTH)
//
// prints a hexadecimal dump of the file 'fn'. Per line WIDTH characters are printed.
// Returns EXIT_SUCCESS if no error occured,
// EXIT_FAILURE otherwise
//
int hexdump(char *fn, int WIDTH)
{
  int fd;
  unsigned char buffer[WIDTH];  // since of C99
  int len, i;

  // open the file
  fd = open(fn, O_RDONLY);
  if (fd == -1) {
    perror("Cannot open file. Reason");
    return EXIT_FAILURE;
  }

  // read from the file until we enounter an error (len < 0) or reach the EOF (len == 0)
  while ((len = read(fd, buffer, sizeof(buffer))) > 0) {
    for (i=0; i<len; i++) printf(" %02x", buffer[i]);
    for (   ; i<sizeof(buffer); i++) printf("   ");
    printf("    ");
    for (i=0; i<len; i++) printf("%c", buffer[i] >= ' ' ? buffer[i] : '.');
    printf("\n");
  }

  // if we encountered an error while reading, print the reason
  if (len < 0) {
    perror("Error reading from file. Reason");
    // do not exit, continue to close the file
  }

  // close the file
  if (close(fd) == -1) {
    perror("Cannot close file. Reason");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
