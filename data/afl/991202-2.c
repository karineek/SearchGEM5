// Modification timestamp: 2023-08-14 13:57:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991202-2.c

#include <stdio.h>
#include <stdlib.h>

int f1(int argc, char *argv[]) {
  unsigned long x, y = 1;

  x = ((y * atoi(argv[1])) - atoi(argv[2])) % atoi(argv[3]);
  return x;
}

int main(int argc, char *argv[]) {
  if (f1(argc, argv) != atoi(argv[4])) {
    abort();
  }
  exit(0);
}
