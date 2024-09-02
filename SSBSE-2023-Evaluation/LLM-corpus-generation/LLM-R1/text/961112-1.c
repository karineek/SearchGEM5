// Modification timestamp: 2023-08-14 13:47:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961112-1.c
f (x)
{
  if (x != 0 || x == 0)
    return 0;
  return 1;
}

main ()
{
  if (f (3))
    abort ();
  exit (0);
}
