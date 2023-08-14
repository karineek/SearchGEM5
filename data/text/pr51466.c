// Modification timestamp: 2023-08-14 15:20:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr51466.c
/* PR tree-optimization/51466 */

extern void abort (void);

__attribute__((noinline, noclone)) int
foo (int i)
{
  volatile int v[4];
  int *p;
  v[i] = 6;
  p = (int *) &v[i];
  return *p;
}

__attribute__((noinline, noclone)) int
bar (int i)
{
  volatile int v[4];
  int *p;
  v[i] = 6;
  p = (int *) &v[i];
  *p = 8;
  return v[i];
}

__attribute__((noinline, noclone)) int
baz (int i)
{
  volatile int v[4];
  int *p;
  v[i] = 6;
  p = (int *) &v[0];
  *p = 8;
  return v[i];
}

int
main ()
{
  if (foo (3) != 6 || bar (2) != 8 || baz (0) != 8 || baz (1) != 6)
    abort ();
  return 0;
}
