//--------------------------------------------------------------------------------------------------
// M1522.000800 System Programming                                        Seoul National University
//
// Author: Bernhard Egger <bernhard@csap.snu.ac.kr>
// (C) Computer Systems and Platforms Laboratory, Seoul National University
//
// Simple Unix I/O example showing how to copy data from a source to a destination file.
//

#define _GNU_SOURCE
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define min(a,b) ((a)<(b)?(a):(b))

int main(int argc, char *argv[])
{
  //
  // print command line arguments
  //
  printf("Command line arguments:\n");
  for (int i=0; i<argc; i++) {
    printf("  %2d: '%s'\n", i, argv[i]);
  }

  //
  // check number of command line arguments
  //
  if (argc != 5) {
    fprintf(stderr, "Error: invalid number of command line parameters.\n"
        "\n"
        "Syntax: %s <src> <dst> <src pos> <bytes>\n"
        "\n"
        "where\n"
        "  src     path to source file\n"
        "  dst     path to destination file (append to existing, create if not present)\n"
        "  src_pos position in input file (>0: position from start, <0: position from end)\n"
        "  bytes   number of bytes to copy\n",
        basename(argv[0]));
    return EXIT_FAILURE;
  }

  //
  // open input and output file
  //
  printf("Opening input file '%s'...\n", argv[1]);
  int fin = open(argv[1], O_RDONLY);
  if (fin == -1) {
    perror("Cannot open input file");
    return EXIT_FAILURE;
  }

  printf("Opening output file '%s'...\n", argv[2]);
  int fout = open(argv[2], O_WRONLY|O_APPEND|O_CREAT, S_IRUSR|S_IWUSR | S_IRGRP | S_IROTH);
  if (fout == -1) {
    perror("Cannot open output file");
    return EXIT_FAILURE;
  }

  //
  // seek in input file
  //
  off_t ofs = atol(argv[3]);
  printf("Seeking input file to position %lu...\n", ofs);
  ofs = lseek(fin, ofs, ofs >= 0 ? SEEK_SET : SEEK_END);
  if (ofs == -1) {
    perror("Cannot seek in input file");
    return EXIT_FAILURE;
  }

  //
  // copy data
  //
  size_t bytes = 0, total = atol(argv[4]);
  char buffer[64*1024];
  printf("Copying %lu bytes...\n", total);
  while (bytes < total) {
    ssize_t read_num = min(sizeof(buffer), total-bytes);
    ssize_t read_res = read(fin, buffer, read_num);

    if (read_res > 0) {
      if (read_res < read_num) {
        printf("  Short count of %ld when trying to read %ld bytes from input\n",
               read_res, read_num);
      }

      ssize_t write_res = write(fout, buffer, read_res);

      if (write_res > 0) {
        if (write_res < read_res) {
          printf("  Short count of %ld when trying to write %ld bytes to output\n",
                 write_res, read_res);
        }

        bytes += write_res;
      } else {
        if (write_res < 0) perror("Error writing to output file");
        break;
      }


    } else {
      if (read_res < 0) perror("Error reading from input file");
      break;
    }
  }
  printf("  copied a total of %lu bytes.\n", bytes);

  //
  // close files
  //
  printf("Closing files...\n");
  close(fin);
  close(fout);

  return EXIT_SUCCESS;
}
