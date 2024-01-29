// Modification timestamp: 2023-08-14 13:00:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041210-1.c
/* The FR-V port used to fail this test because the andcc patterns
   wrongly claimed to set the C and V flags.  */
#include <limits.h>

int x[4] = { INT_MIN / 2, INT_MAX, 2, 4 };

int
main ()
{
  if (x[0] < x[1])
    if ((x[2] & x[3]) < 0)
      abort ();
  exit (0);
}
