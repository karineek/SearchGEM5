// Modification timestamp: 2023-08-14 13:52:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990117-1.c

#include <stdio.h>
#include <stdlib.h>

int foo(int x, int y, int i, int j) {
  double tmp1 = ((double) x / y);
  double tmp2 = ((double) i / j);

  return tmp1 < tmp2;
}

int main(int argc, char *argv[]) {
  if (foo(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])) == 0)
    abort();
  return 0;
}
