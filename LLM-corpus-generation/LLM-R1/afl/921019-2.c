// Modification timestamp: 2023-08-14 13:30:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921019-2.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double x, y = atof(argv[1]);
  x = y / atof(argv[2]);
  if (x != x)
    abort();
  exit(0);
}
