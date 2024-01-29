// Modification timestamp: 2023-08-14 15:55:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr80501.c

#include <stdio.h>
#include <stdlib.h>

signed char v = 0;

static signed char
foo (int x, int y)
{
  return x << y;
}

__attribute__((noinline, noclone)) int
bar (signed char v, int x, int y)
{
  return foo (v >= 0, __CHAR_BIT__ - 1) >= 1;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  signed char v = atoi(argv[1]);
  if (sizeof (int) > sizeof (char) && bar (v, 0, 0) != 0)
    __builtin_abort ();
  return 0;
}
