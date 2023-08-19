// Modification timestamp: 2023-08-14 13:53:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990222-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char line[4] = { argv[1][0], argv[1][1], argv[1][2], '\0' };

  char *ptr = line + 3;

  while ((*--ptr += 1) > '9') *ptr = '0';
  if (line[0] != '2' || line[1] != '0' || line[2] != '0')
    abort();
  return 0;
}
