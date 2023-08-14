// Modification timestamp: 2023-08-14 13:35:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930818-1.c
static double one = 1.0;

f()
{
  int colinear;
  colinear = (one == 0.0);
  if (colinear)
    abort ();
  return colinear;
}
main()
{
  if (f()) abort();
  exit (0);
}
