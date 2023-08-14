// Modification timestamp: 2023-08-14 12:38:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021119-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int foo(int i, int x)
{
  int r;
  r = (x - 4 * i) / 20;
  return r;
}

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s <i> <x>\n", argv[0]);
    return 1;
  }

  int i = atoi(argv[1]);
  int x = atoi(argv[2]);

  if (foo(i, x) != 3)
    abort();

  return 0;
}
