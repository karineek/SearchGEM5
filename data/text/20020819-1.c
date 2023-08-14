// Modification timestamp: 2023-08-14 12:36:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020819-1.c
foo ()
{
  return 0;
}

main()
{
  int i, j, k, ccp_bad = 0;

  for (i = 0; i < 10; i++)
    {
      for (j = 0; j < 10; j++)
	if (foo ())
	  ccp_bad = 1;

      k = ccp_bad != 0;
      if (k)
	abort ();
    }

  exit (0);
}
