// Modification timestamp: 2023-08-14 13:57:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991112-1.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int rl_show_char (int c) { return 0; }

int rl_character_len (int c, int pos)
{
  return isprint (c) ? 1 : 2;
}

int main(int argc, char *argv[]) {
  int (*x)(int, int) = rl_character_len;
  
  if (x(argv[1][0], atoi(argv[2])) != atoi(argv[3])) {
    abort();
  }
  
  if (x(argv[4][0], atoi(argv[5])) != atoi(argv[6])) {
    abort();
  }
  
  return 0;
}

