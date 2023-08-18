// Modification timestamp: 2023-08-14 13:31:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921123-1.c

#include <stdio.h>
#include <stdlib.h>

int f(short *p) {
  short x = *p;
  return (--x < 0);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  short x = atoi(argv[1]);
  if (!f(&x))
    abort();
  exit(0);
}
