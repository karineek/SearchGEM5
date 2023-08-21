// Modification timestamp: 2023-08-14 14:44:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr19449.c
#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

int y;
int z = __builtin_choose_expr (!__builtin_constant_p (y), 3, 4);

int foo(int x, int y)
{
  return __builtin_choose_expr (!__builtin_constant_p (x), 3, y++);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int y = atoi(argv[1]);
  int z = __builtin_choose_expr (!__builtin_constant_p (y), 3, 4);

  if (y || z != 3 || foo(4, y) != 3)
    abort ();

  return 0;
}
