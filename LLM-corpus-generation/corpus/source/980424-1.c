// Modification timestamp: 2023-08-14 13:48:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980424-1.c

#include <stdio.h>
#include <stdlib.h>

int i, a[99];

void f(int one) {
  if (one != 1)
    abort();
}

void g() {
  f(a[i & 0x3f]);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  a[0] = atoi(argv[1]);
  i = atoi(argv[2]);
  g();
  exit(0);
}
