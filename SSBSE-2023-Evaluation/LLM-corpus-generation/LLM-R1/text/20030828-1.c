// Modification timestamp: 2023-08-14 12:48:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030828-1.c
const int *p;

int bar (void)
{
  return *p + 1;
}

main ()
{
  /* Variable 'i' is never used but it's aliased to a global pointer.  The
     alias analyzer was not considering that 'i' may be used in the call to
     bar().  */
  const int i = 5;
  p = &i;
  if (bar() != 6)
    abort ();
  exit (0);
}
