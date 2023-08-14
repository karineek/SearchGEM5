// Modification timestamp: 2023-08-14 14:17:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/compare-2.c

#include <stdio.h>
#include <stdlib.h>

int foo(int x, int y)
{
  /* If miscompiled the following may become "x == y".  */
  return (x<=y) && ((unsigned int)x >= (unsigned int)y);
}

int main()
{
  int x = atoi(argv[1]);
  int y = atoi(argv[2]);

  if (!foo(x, y))
    abort ();
  return 0;
}
