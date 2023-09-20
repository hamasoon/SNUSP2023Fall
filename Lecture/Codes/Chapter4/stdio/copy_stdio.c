//--------------------------------------------------------------------------------------------------
// M1522.000800 System Programming                                        Seoul National University
//
// Author: Bernhard Egger <bernhard@csap.snu.ac.kr>
// (C) Computer Systems and Platforms Laboratory, Seoul National University
//
// Comparing the performance of Unix I/O and Standard I/O single-character copy
// This file implements a Standard I/O copy. Compare to copy_unixio.c with meld.
//

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



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
  FILE *fin = fopen(argv[1], "r");
  if (fin == NULL) {
    perror("Cannot open input file");
    return EXIT_FAILURE;
  }

  FILE *fout = fopen(argv[2], "w");
  if (fout == NULL) {
    perror("Cannot open output file");
    return EXIT_FAILURE;
  }

  //
  // single-byte copy loop
  //
  size_t total = atol(argv[3]);
  char c;
  while (total > 0) {
    if ((fread(&c, 1, 1, fin) < 1) || (fwrite(&c, 1, 1, fout) < 1)) break; // halt on read or write errors
    total--;
  }

  //
  // close files
  //
  fclose(fin);
  fclose(fout);

  return EXIT_SUCCESS;
}
