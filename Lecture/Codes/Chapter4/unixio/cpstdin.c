//--------------------------------------------------------------------------------------------------
// M1522.000800 System Programming                                        Seoul National University
//
// Author: Bernhard Egger <bernhard@csap.snu.ac.kr>
// (C) Computer Systems and Platforms Laboratory, Seoul National University
//
// Simplistic Unix I/O example: copy STDIN to STDOUT one character at a time
//

#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  char c;

  while (read(STDIN_FILENO, &c, 1) != 0) {
    write(STDOUT_FILENO, &c, 1);
  }

  return EXIT_SUCCESS;
}

