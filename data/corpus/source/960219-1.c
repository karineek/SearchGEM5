// Modification timestamp: 2023-08-14 13:44:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960219-1.c

#include <stdio.h>
#include <stdlib.h>

void f(int i) {
  if (((1 << i) & 1) == 0)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);

  f(i);
  exit(0);
}
