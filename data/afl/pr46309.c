// Modification timestamp: 2023-08-14 15:14:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr46309.c

#include <stdio.h>
#include <stdlib.h>

unsigned int *q;

__attribute__((noinline, noclone)) void bar (unsigned int *p) {
  if (*p != 2 && *p != 3)
    (!(!(*q & 263) || *p != 1)) ? abort () : 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int x, y;
  asm volatile ("" : : : "memory");
  x = atoi(argv[1]);
  bar(&x);
  return 0;
}
