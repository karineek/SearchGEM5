// Modification timestamp: 2023-08-14 13:43:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950915-1.c
long int a = 100000;
long int b = 21475;

long
f ()
{
  return ((long long) a * (long long) b) >> 16;
}

main ()
{
  if (f () < 0)
    abort ();
  exit (0);
}
