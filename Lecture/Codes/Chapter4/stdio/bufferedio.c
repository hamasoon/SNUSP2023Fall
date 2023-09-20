//--------------------------------------------------------------------------------------------------
// M1522.000800 System Programming                                        Seoul National University
//
// Author: Bernhard Egger <bernhard@csap.snu.ac.kr>
// (C) Computer Systems and Platforms Laboratory, Seoul National University
//
// Observing system calls made with Unix and Standard I/O. Run with strace.
//
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void unix_io(void)
{
  char c;

  sleep(1); c = 'h'; write(1, &c, sizeof(c));
  sleep(1); c = 'e'; write(1, &c, sizeof(c));
  sleep(1); c = 'l'; write(1, &c, sizeof(c));
  sleep(1); c = 'l'; write(1, &c, sizeof(c));
  sleep(1); c = 'o'; write(1, &c, sizeof(c));
  sleep(1); c = '\n'; write(1, &c, sizeof(c));

  sleep(1); c = 'h'; write(1, &c, sizeof(c));
  sleep(1); c = 'e'; write(1, &c, sizeof(c));
  sleep(1); c = 'l'; write(1, &c, sizeof(c));
  sleep(1); c = 'l'; write(1, &c, sizeof(c));
  sleep(1); c = 'o'; write(1, &c, sizeof(c));
  sleep(1); c = ','; write(1, &c, sizeof(c));
  sleep(1); c = 'w'; write(1, &c, sizeof(c));
  sleep(1); c = 'o'; write(1, &c, sizeof(c));
  sleep(1); c = 'r'; write(1, &c, sizeof(c));
  sleep(1); c = 'l'; write(1, &c, sizeof(c));
  sleep(1); c = 'd'; write(1, &c, sizeof(c));
  sleep(1); c = '\n'; write(1, &c, sizeof(c));
}

void standard_io(void)
{
  // force line buffering
  setvbuf(stdout, NULL, _IOLBF, 0);

  sleep(1); printf("h");
  sleep(1); printf("e");
  sleep(1); printf("ll");
  sleep(1); printf("o");
  sleep(1); printf("\n");

  sleep(1); printf("h");
  sleep(1); printf("e");
  sleep(1); printf("ll");
  sleep(1); printf("o");
  sleep(1); printf(","); fflush(stdout);
  sleep(1); printf("w");
  sleep(1); printf("o");
  sleep(1); printf("r");
  sleep(1); printf("l");
  sleep(1); printf("d");
  sleep(1); printf("\n");
}

int main(int argc, char *argv[])
{
  if (argc == 1) unix_io();
  else standard_io();

  return EXIT_SUCCESS;
}
