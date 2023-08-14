// Modification timestamp: 2023-08-14 13:17:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20090623-1.c
int * __restrict__ x;

int foo (int y)
{
  *x = y;
  return *x;
}

extern void abort (void);

int main()
{
  int i = 0;
  x = &i;
  if (foo(1) != 1)
    abort ();
  return 0;
}
