// Modification timestamp: 2023-08-14 12:56:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040706-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;
  for (i = 0; i < atoi(argv[1]); i++)
    continue;
  if (i < atoi(argv[2]))
    abort();
  exit(0);
}
