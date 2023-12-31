// Modification timestamp: 2023-08-14 12:50:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031020-1.c
/* PR target/12654
   The Alpha backend tried to do a >= 1024 as (a - 1024) >= 0, which fails
   for very large negative values.  */
/* Origin: tg@swox.com  */

#include <limits.h>

extern void abort (void);

void __attribute__((noinline))
foo (long x)
{
  if (x >= 1024)
    abort ();
}

int
main ()
{
  foo (LONG_MIN);
  foo (LONG_MIN + 10000);
  return 0;
}
