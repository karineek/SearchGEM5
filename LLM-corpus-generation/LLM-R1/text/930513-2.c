// Modification timestamp: 2023-08-14 13:33:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930513-2.c
sub3 (i)
     const int *i;
{
}

eq (a, b)
{
  static int i = 0;
  if (a != i)
    abort ();
  i++;
}

main ()
{
  int i;

  for (i = 0; i < 4; i++)
    {
      const int j = i;
      int k;
      sub3 (&j);
      k = j;
      eq (k, k);
    }
  exit (0);
}
