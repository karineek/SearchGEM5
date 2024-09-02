// Modification timestamp: 2023-08-14 14:17:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/comp-goto-2.c

#include <stdio.h>
#include <stdlib.h>

#ifdef STACK_SIZE
#define DEPTH ((STACK_SIZE) / 512 + 1)
#else
#define DEPTH 1000
#endif

void y(int a) {
  void *x = &&llab;
  if (a == -1)
    goto *x;
  if (a == 0)
    goto xlab;
llab:
  y(a - 1);
}

int x(int a) {
  __label__ xlab;
  y(a);
xlab:;
  return a;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int DEPTH = atoi(argv[1]);
  if (x(DEPTH) != DEPTH) {
    abort();
  }

  exit(0);
}

