// Modification timestamp: 2023-08-14 12:45:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030403-1.c
/* The non-destructive folder was always emitting >= when folding
   comparisons to signed_max+1.  */

#include <limits.h>

int
main ()
{
  unsigned long count = 8;

  if (count > INT_MAX)
    abort ();

  return (0);
}
