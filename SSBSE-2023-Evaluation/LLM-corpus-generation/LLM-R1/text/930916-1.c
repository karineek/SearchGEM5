// Modification timestamp: 2023-08-14 13:35:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930916-1.c
f (n)
     unsigned n;
{
  if ((int) n >= 0)
    abort ();
}

main ()
{
  unsigned x = ~0;
  f (x);
  exit (0);
}
