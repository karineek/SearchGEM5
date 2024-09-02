// Modification timestamp: 2023-08-14 13:39:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931009-1.c
main ()
{
  f ();
  exit (0);
}

static
g (out, size, lo, hi)
     int *out, size, lo, hi;
{
  int j;

  for (j = 0; j < size; j++)
    out[j] = j * (hi - lo);
}


f ()
{
  int a[2];

  g (a, 2, 0, 1);

  if (a[0] != 0 || a[1] != 1)
    abort ();
}
