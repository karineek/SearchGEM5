// Modification timestamp: 2023-08-14 13:47:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961112-1.c

#include <stdio.h>
#include <stdlib.h>

int f(int x) {
  if (x != 0 || x == 0)
    return 0;
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  if (f(x))
    abort();
  exit(0);
}
