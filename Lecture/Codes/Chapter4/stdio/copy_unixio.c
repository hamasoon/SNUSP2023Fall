//--------------------------------------------------------------------------------------------------
// M1522.000800 System Programming                                        Seoul National University
//
// Author: Bernhard Egger <bernhard@csap.snu.ac.kr>
// (C) Computer Systems and Platforms Laboratory, Seoul National University
//
// Comparing the performance of Unix I/O and Standard I/O single-character copy
// This file implements a Unix I/O copy. Compare to copy_stdio.c with meld.
//

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  //
  // check number of command line arguments
  //
  if (argc != 4) {
    fprintf(stderr, "Error: invalid number of command line parameters.\n"
        "\n"
        "Syntax: %s <src> <dst> <bytes>\n"
        "\n"
        "where\n"
        "  src     path to source file\n"
        "  dst     path to destination file\n"
        "  bytes   number of bytes to copy\n",
        basename(argv[0]));
    return EXIT_FAILURE;
  }

  //
  // open input and output file
  //
  int fin = open(argv[1], O_RDONLY);
  if (fin == -1) {
    perror("Cannot open input file");
    return EXIT_FAILURE;
  }

  int fout = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, S_IRUSR|S_IWUSR | S_IRGRP | S_IROTH);
  if (fout == -1) {
    perror("Cannot open output file");
    return EXIT_FAILURE;
  }

  //
  // single-byte copy loop
  //
  size_t total = atol(argv[3]);
  char c;
  while (total > 0) {
    if ((read(fin, &c, 1) < 1) || (write(fout, &c, 1) < 1)) break; // halt on read or write errors
    total--;
  }

  //
  // close files
  //
  close(fin);
  close(fout);

  return EXIT_SUCCESS;
}
