// Modification timestamp: 2023-08-14 13:17:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20090814-1.c
int __attribute__((noinline))
bar (int *a)
{
  return *a;
}
int i;
int __attribute__((noinline))
foo (int (*a)[2])
{
  return bar (&(*a)[i]);
}

extern void abort (void);
int a[2];
int main()
{
  a[0] = -1;
  a[1] = 42;
  i = 1;
  if (foo (&a) != 42)
    abort ();
  return 0;
}
