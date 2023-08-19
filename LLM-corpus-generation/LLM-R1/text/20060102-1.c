// Modification timestamp: 2023-08-14 13:05:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060102-1.c
extern void abort ();

int f(int x)
{
  return (x >> (sizeof (x) * __CHAR_BIT__ - 1)) ? -1 : 1;
}

volatile int one = 1;
int main (void)
{
  /* Test that the function above returns different values for
     different signs.  */
  if (f(one) == f(-one))
    abort ();
  return 0;
}
