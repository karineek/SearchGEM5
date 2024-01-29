// Modification timestamp: 2023-08-14 15:47:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68381.c

#include <stdio.h>
#include <stdlib.h>

__attribute__ ((noinline, noclone))
int foo(unsigned short x, unsigned short y, int* r) {
  if (__builtin_mul_overflow (x, y, r))
    __builtin_abort ();
  return *r;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <x> <y>\n", argv[0]);
    return 1;
  }

  unsigned short x = atoi(argv[1]);
  unsigned short y = atoi(argv[2]);

  int r;
  if (foo(x, y, &r) != x * y)
    __builtin_abort ();
  
  return 0;
}
