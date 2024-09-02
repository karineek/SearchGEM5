// Modification timestamp: 2023-08-14 13:45:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960402-1.c
f (signed long long int x)
{
  return x > 0xFFFFFFFFLL || x < -0x80000000LL;
}

main ()
{
  if (f (0) != 0)
    abort ();
  exit (0);
}
