// Modification timestamp: 2023-08-14 16:06:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pta-field-2.c
struct Foo {
  int *p;
  int *q;
};

void __attribute__((noinline))
bar (int **x)
{
  struct Foo *f = (struct Foo *)(x - 1);
  *(f->p) = 0;
}

int foo(void)
{
  struct Foo f;
  int i = 1, j = 2;
  f.p = &i;
  f.q = &j;
  bar(&f.q);
  return i;
}

extern void abort (void);
int main()
{
  if (foo () != 0)
    abort ();
  return 0;
}
