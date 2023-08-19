// Modification timestamp: 2023-08-14 13:58:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991216-2.c
#include <stdarg.h>

#define VALUE 0x123456789abcdefLL
#define AFTER 0x55

void
test (int n, ...)
{
  va_list ap;
  int i;

  va_start (ap, n);
  for (i = 2; i <= n; i++)
    {
      if (va_arg (ap, int) != i)
	abort ();
    }

  if (va_arg (ap, long long) != VALUE)
    abort ();

  if (va_arg (ap, int) != AFTER)
    abort ();

  va_end (ap);
}

int
main ()
{
  test (1, VALUE, AFTER);
  test (2, 2, VALUE, AFTER);
  test (3, 2, 3, VALUE, AFTER);
  test (4, 2, 3, 4, VALUE, AFTER);
  test (5, 2, 3, 4, 5, VALUE, AFTER);
  test (6, 2, 3, 4, 5, 6, VALUE, AFTER);
  test (7, 2, 3, 4, 5, 6, 7, VALUE, AFTER);
  test (8, 2, 3, 4, 5, 6, 7, 8, VALUE, AFTER);
  exit (0);
}
