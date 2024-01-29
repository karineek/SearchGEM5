// Modification timestamp: 2023-08-14 13:41:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950322-1.c

#include <stdio.h>
#include <stdlib.h>

int f(unsigned char *a) {
  int i, j;
  int x, y;

  j = a[1];
  i = a[0] - j;
  if (i < 0) {
    x = 1;
    y = -i;
  } else {
    x = 0;
    y = i;
  }
  return x + y;
}

int main(int argc, char *argv[]) {
  unsigned char a[2];
  a[0] = atoi(argv[1]);
  a[1] = atoi(argv[2]);
  if (f(a) != atoi(argv[3])) {
    abort();
  }
  exit(0);
}


Please make sure to pass the arguments when running the program, e.g., `./program 8 9 2`.