// Modification timestamp: 2023-08-14 13:01:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050111-1.c
/* PR middle-end/19084, rtl-optimization/19348 */

unsigned int
foo (unsigned long long x)
{
  unsigned int u;

  if (x == 0)
    return 0;
  u = (unsigned int) (x >> 32);
  return u;
}

unsigned long long
bar (unsigned short x)
{
  return (unsigned long long) x << 32;
}

extern void abort (void);

int
main (void)
{
  if (sizeof (long long) != 8)
    return 0;

  if (foo (0) != 0)
    abort ();
  if (foo (0xffffffffULL) != 0)
    abort ();
  if (foo (0x25ff00ff00ULL) != 0x25)
    abort ();
  if (bar (0) != 0)
    abort ();
  if (bar (0x25) != 0x2500000000ULL)
    abort ();
  return 0;
}
