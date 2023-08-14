// Modification timestamp: 2023-08-14 13:44:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960302-1.c
long a = 1;

foo ()
{
  switch (a % 2 % 2 % 2 % 2 % 2 % 2 % 2 % 2)
    {
    case 0:
      return 0;
    case 1:
      return 1;
    default:
      return -1;
    }
}

main ()
{
  if (foo () != 1)
    abort ();
  exit (0);
}
