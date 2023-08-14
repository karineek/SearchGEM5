// Modification timestamp: 2023-08-14 13:47:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961004-1.c
int k = 0;

main()
{
  int i;
  int j;

  for (i = 0; i < 2; i++)
    {
      if (k)
	{
	  if (j != 2)
	    abort ();
	}
      else
	{
	  j = 2;
	  k++;
	}
    }
  exit (0);
}
