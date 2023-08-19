// Modification timestamp: 2023-08-14 13:02:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050131-1.c
/* Verify that we do not lose side effects on a MOD expression.  */

#include <stdlib.h>
#include <stdio.h>

int
foo (int a)
{
  int x = 0 % a++;
  return a;
}

main()
{
  if (foo (9) != 10)
    abort ();
  exit (0);
}
