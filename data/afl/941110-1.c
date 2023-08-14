// Modification timestamp: 2023-08-14 13:41:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941110-1.c

#include <stdio.h>
#include <stdlib.h>

int f(const int x) {
  int y = 0;
  y = x ? y : -y;
  {
    const int *p = &x;
  }
  return y;
}

int main(int argc, char *argv[]) {
  if (f(atoi(argv[1])))
    abort();
  exit(0);
}
