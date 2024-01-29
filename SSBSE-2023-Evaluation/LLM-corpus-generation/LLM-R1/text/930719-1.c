// Modification timestamp: 2023-08-14 13:35:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930719-1.c
int
f (foo, bar, com)
{
  unsigned align;
  if (foo)
    return 0;
  while (1)
    {
      switch (bar)
	{
	case 1:
	  if (com != 0)
	    return align;
	  *(char *) 0 = 0;
	}
    }
}

main ()
{
  f (0, 1, 1);
  exit (0);
}
