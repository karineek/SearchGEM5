// Modification timestamp: 2023-08-14 11:57:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010221-1.c

int n = 2;

main ()
{
  int i, x = 45;

  for (i = 0; i < n; i++)
    {
      if (i != 0)
	x = ( i > 0 ) ? i : 0;
    }

  if (x != 1)
    abort ();
  exit (0);
}
