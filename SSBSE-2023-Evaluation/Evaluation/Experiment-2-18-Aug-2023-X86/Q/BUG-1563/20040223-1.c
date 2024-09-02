// Modification timestamp: 2023-08-14 12:51:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040223-1.c

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void a(void *x, int y) {
  if (y != 1234)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  a(strcpy(alloca(100), argv[1]), 1234);
  return 0;
}
