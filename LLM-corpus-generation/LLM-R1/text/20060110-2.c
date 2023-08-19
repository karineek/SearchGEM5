// Modification timestamp: 2023-08-14 13:06:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060110-2.c
extern void abort (void);

long long
f (long long a, long long b)
{
  return ((a + b) << 32) >> 32;
}

long long a = 0x1234567876543210LL;
long long b = 0x2345678765432101LL;
long long c = ((0x1234567876543210LL + 0x2345678765432101LL) << 32) >> 32;

int
main ()
{
  if (f (a, b) != c)
    abort ();
  return 0;
}
