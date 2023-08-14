// Modification timestamp: 2023-08-14 13:39:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931012-1.c

#include <stdio.h>
#include <stdlib.h>

int f(int b, int c) {
  if (b != 0 && b != 1 && c != 0)
    b = 0;
  return b;
}

int main(int argc, char *argv[]) {
  if (!f(atoi(argv[1]), atoi(argv[2])))
    abort();
  exit(0);
}
