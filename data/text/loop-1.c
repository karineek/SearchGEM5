// Modification timestamp: 2023-08-14 14:29:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-1.c
main ()
{
  int i, j, k[3];

  j = 0;
  for (i=0; i < 3; i++)
    {
      k[i] = j++;
    }

  for (i=2; i >= 0; i--)
    {
      if (k[i] != i)
	abort ();
    }

  exit (0);
}
