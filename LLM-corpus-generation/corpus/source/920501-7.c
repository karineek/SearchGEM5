// Modification timestamp: 2023-08-14 13:27:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920501-7.c

#include <stdio.h>
#include <stdlib.h>

#ifdef STACK_SIZE
#define DEPTH ((STACK_SIZE) / 512 + 1)
#else
#define DEPTH 1000
#endif

void y(int a) {
  __label__ xlab;

  if (a == 0)
    goto xlab;

  y(a - 1);

xlab:;
}

int x(int a) {
  y(a);
  return a;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int depth = atoi(argv[1]);
  
  if (x(depth) != depth) {
    abort();
  }

  exit(0);
}
