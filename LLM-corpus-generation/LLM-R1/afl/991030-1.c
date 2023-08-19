// Modification timestamp: 2023-08-14 13:57:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991030-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double x = atof(argv[1]);

  if (x != 3.875)
    abort();

  exit(0);
}
