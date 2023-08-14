// Modification timestamp: 2023-08-14 13:33:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930429-2.c

#include <stdio.h>
#include <stdlib.h>

int f(int b) {
  return (b >> 1) > 0;
}

int main(int argc, char *argv[]) {
  if (!f(atoi(argv[1]))) {
    abort();
  }
  if (f(atoi(argv[2]))) {
    abort();
  }
  exit(0);
}
