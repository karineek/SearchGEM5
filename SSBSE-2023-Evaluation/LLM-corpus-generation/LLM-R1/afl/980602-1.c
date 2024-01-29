// Modification timestamp: 2023-08-14 13:49:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980602-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;
  for (i = 1; i < 100; i++)
    ;
  if (i == atoi(argv[1]))
    exit(0);
  abort();
}
