// Modification timestamp: 2023-08-14 13:17:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20090207-1.c
int foo(int i)
{
  int a[32];
  a[1] = 3;
  a[0] = 1;
  a[i] = 2;
  return a[0];
}
extern void abort (void);
int main()
{
  if (foo (0) != 2
      || foo (1) != 1)
    abort ();
  return 0;
}
