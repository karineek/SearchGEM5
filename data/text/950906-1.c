// Modification timestamp: 2023-08-14 13:43:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950906-1.c
g (int i)
{
}

f (int i)
{
  g (0);
  while ( ({ i--; }) )
    g (0);
}

main ()
{
  f (10);
  exit (0);
}
