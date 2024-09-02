// Modification timestamp: 2023-08-14 14:25:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/divconst-3.c
long long
f (long long x)
{
  return x / 10000000000LL;
}

main ()
{
  if (f (10000000000LL) != 1 || f (100000000000LL) != 10)
    abort ();
  exit (0);
}
