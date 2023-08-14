// Modification timestamp: 2023-08-14 13:44:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960219-1.c
f (int i)
{
  if (((1 << i) & 1) == 0)
    abort ();
}

main ()
{
  f (0);
  exit (0);
}
