// Modification timestamp: 2023-08-14 11:59:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010717-1.c
extern void abort (void);

int
main ()
{
  int i, j;
  unsigned long u, r1, r2;

  i = -16;
  j = 1;
  u = i + j;

  /* no sign extension upon shift */
  r1 = u >> 1;
  /* sign extension upon shift, but there shouldn't be */
  r2 = ((unsigned long) (i + j)) >> 1;

  if (r1 != r2)
    abort ();

  return 0;
}
