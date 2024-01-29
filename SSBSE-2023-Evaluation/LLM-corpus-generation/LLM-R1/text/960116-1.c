// Modification timestamp: 2023-08-14 13:43:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960116-1.c
static inline
p (int *p)
{
  return !((long) p & 1);
}

int
f (int *q)
{
  if (p (q) && *q)
    return 1;
  return 0;
}

main ()
{
  if (f ((int*) 0xffffffff) != 0)
    abort ();
  exit (0);
}
