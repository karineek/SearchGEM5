// Modification timestamp: 2023-08-14 13:41:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950322-1.c
f (unsigned char *a)
{
  int i, j;
  int x, y;

  j = a[1];
  i = a[0] - j;
  if (i < 0)
    {
      x = 1;
      y = -i;
    }
  else
    {
      x = 0;
      y =  i;
    }
  return x + y;
}


main ()
{
  unsigned char a[2];
  a[0] = 8;
  a[1] = 9;
  if (f (a) != 2)
    abort ();
  exit (0);
}
