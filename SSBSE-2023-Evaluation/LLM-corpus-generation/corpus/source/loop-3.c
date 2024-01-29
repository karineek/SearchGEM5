// Modification timestamp: 2023-08-14 14:31:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-3.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n = 0;

void g(int i) {
  n++;
}

void f(int m) {
  int i;
  i = m;
  do {
    g(i * INT_MAX / 2);
  } while (--i > 0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int m = atoi(argv[1]);
  f(m);
  if (n != m) {
    abort();
  }
  exit(0);
}
