// Modification timestamp: 2023-08-14 15:02:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr38212.c
int __attribute__((noinline))
foo (int *__restrict p, int i)
{
  int *__restrict q;
  int *__restrict r;
  int v, w;
  q = p + 1;
  r = q - i;
  v = *r;
  *p = 1;
  w = *r;
  return v + w;
}
extern void abort (void);
int main()
{
  int i = 0;
  if (foo (&i, 1) != 1)
    abort ();
  return 0;
}
