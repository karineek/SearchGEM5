// Modification timestamp: 2023-08-14 13:06:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060127-1.c
void abort ();

void
f (long long a)
{
  if ((a & 0xffffffffLL) != 0)
    abort ();
}

long long a = 0x1234567800000000LL;

int
main ()
{
  f (a);
  return 0;
}
