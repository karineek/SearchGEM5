// Modification timestamp: 2023-08-14 13:43:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/951204-1.c
f (char *x)
{
  *x = 'x';
}

main ()
{
  int i;
  char x = '\0';

  for (i = 0; i < 100; ++i)
    {
      f (&x);
      if (*(const char *) &x != 'x')
	abort ();
    }
  exit (0);
}
