// Modification timestamp: 2023-08-14 15:39:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr61517.c

#include <stdio.h>
#include <stdlib.h>

int a, b, *c = &a;
unsigned short d;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int e = atoi(argv[1]);
  *c = 1;
  if (!b) {
    d = e;
    *c = d | e;
  }

  if (a != 0)
    abort();

  return 0;
}
