//--------------------------------------------------------------------------------------------------
// M1522.000800 System Programming                                        Seoul National University
//
// Author: Bernhard Egger <bernhard@csap.snu.ac.kr>
// (C) Computer Systems and Platforms Laboratory, Seoul National University
//
// Hello, world! using Unix I/O
//

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char str[] = "Hello, world!\n";

int main(void)
{
  write(STDOUT_FILENO, str, strlen(str));
  return EXIT_SUCCESS;
}

