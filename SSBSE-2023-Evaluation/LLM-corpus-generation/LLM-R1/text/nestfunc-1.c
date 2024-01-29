// Modification timestamp: 2023-08-14 14:40:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/nestfunc-1.c
/* { dg-require-effective-target trampolines } */

int
g (int a, int b, int (*gi) (int, int))
{
  if ((*gi) (a, b))
    return a;
  else
    return b;
}

f ()
{
  int i, j;
  int f2 (int a, int b)
    {
      return a > b;
    }

  if (g (1, 2, f2) != 2)
    abort ();
}

main ()
{
  f ();
  exit (0);
}
