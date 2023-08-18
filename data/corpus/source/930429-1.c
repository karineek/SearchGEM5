// Modification timestamp: 2023-08-14 13:33:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930429-1.c

#include <stdio.h>
#include <stdlib.h>

char *f(char *p) {
  short x = *p++ << 16;
  return p;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char *p = argv[1];
  if (f(p) != p + 1)
    abort();

  exit(0);
}
