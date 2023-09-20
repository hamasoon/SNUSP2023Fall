//--------------------------------------------------------------------------------------------------
// M1522.000800 System Programming                                        Seoul National University
//
// Author: Bernhard Egger <bernhard@csap.snu.ac.kr>
// (C) Computer Systems and Platforms Laboratory, Seoul National University
//
// Hello, world! using Standard I/O
//

#include <stdio.h>
#include <stdlib.h>

char str[] = "Hello, world!\n";

int main(void)
{
  fprintf(stdout, "%s", str);     // proper use
  printf("%s", str);              // printf() implicitly outputs to stdout

  return EXIT_SUCCESS;
}

