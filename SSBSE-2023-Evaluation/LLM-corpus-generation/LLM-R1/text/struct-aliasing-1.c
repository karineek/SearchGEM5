// Modification timestamp: 2023-08-14 16:52:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/struct-aliasing-1.c
struct S { float f; };
int __attribute__((noinline))
foo (int *r, struct S *p)
{
  int *q = (int *)&p->f;
  int i = *q;
  *r = 0;
  return i + *q;
}
extern void abort (void);
int main()
{
  int i = 1;
  if (foo (&i, (struct S *)&i) != 1)
    abort ();
  return (0);
}
