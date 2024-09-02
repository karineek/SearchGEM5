// Modification timestamp: 2023-08-14 13:39:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931031-1.c

#include <stdio.h>
#include <stdlib.h>

struct foo {
  unsigned y: 1;
  unsigned x: 32;
};

int f(struct foo x) {
  int t = x.x;
  if (t < 0)
    return 1;
  return t + 1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct foo x;
  x.x = atoi(argv[1]);
  if (f(x) == 0)
    abort();
  exit(0);
}

