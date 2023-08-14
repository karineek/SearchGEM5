// Modification timestamp: 2023-08-14 15:36:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59101.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) int
foo (int a)
{
  return (~a & 4102790424LL) > 0 | 6;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg = atoi(argv[1]);
  if (foo(arg) != 7) {
    __builtin_abort ();
  }
  
  return 0;
}
