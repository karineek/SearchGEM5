// Modification timestamp: 2023-08-14 13:43:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950906-1.c

#include <stdio.h>
#include <stdlib.h>

void g(int i) {
}

void f(int i) {
  g(0);
  while ((i--)) {
    g(0);
  }
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
