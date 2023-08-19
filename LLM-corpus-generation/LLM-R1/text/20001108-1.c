// Modification timestamp: 2023-08-14 11:53:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001108-1.c
long long
signed_poly (long long sum, long x)
{
  sum += (long long) (long) sum * (long long) x;
  return sum;
}

unsigned long long
unsigned_poly (unsigned long long sum, unsigned long x)
{
  sum += (unsigned long long) (unsigned long) sum * (unsigned long long) x;
  return sum;
}

int
main (void)
{
  if (signed_poly (2LL, -3) != -4LL)
    abort ();

  if (unsigned_poly (2ULL, 3) != 8ULL)
    abort ();

  exit (0);
}
