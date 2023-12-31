// Modification timestamp: 2023-08-14 12:59:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041126-1.c
extern int abs (int);
extern void abort (void);

void
check (int *p)
{
  int i;
  for (i = 0; i < 5; ++i)
    if (p[i])
      abort ();
  for (; i < 10; ++i)
    if (p[i] != i + 1)
      abort ();
}

int
main (void)
{
  int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int i;

  for (i = -5; i < 0; i++)
    a[abs (i - 10) - 11] = 0;
  check (a);
  return 0;
}
