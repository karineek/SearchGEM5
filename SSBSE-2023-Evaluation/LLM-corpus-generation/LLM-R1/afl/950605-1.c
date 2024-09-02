// Modification timestamp: 2023-08-14 13:41:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950605-1.c

#include <stdio.h>
#include <stdlib.h>

void f(unsigned char c) {
  if (c != 0xFF)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned char c = atoi(argv[1]);
  f(c);
  exit(0);
}
