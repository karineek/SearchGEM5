// Modification timestamp: 2023-08-14 13:41:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/941101-1.c
f ()
{
  int var = 7;

  if ((var/7) == 1)
    return var/7;
  return 0;
}

main ()
{
  if (f () != 1)
    abort ();
  exit (0);
}
