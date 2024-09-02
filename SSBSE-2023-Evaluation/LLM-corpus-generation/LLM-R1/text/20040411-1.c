// Modification timestamp: 2023-08-14 12:54:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040411-1.c
int
sub1 (int i, int j)
{
  typedef int c[i+2];
  int x[10], y[10];

  if (j == 2)
    {
      memcpy (x, y, 10 * sizeof (int));
      return sizeof (c);
    }
  else
    return sizeof (c) * 3;
}

int
main ()
{
  if (sub1 (20, 3) != 66 * sizeof (int))
    abort ();

  return 0;
}
