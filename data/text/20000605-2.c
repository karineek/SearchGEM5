
// Modification timestamp: 2023-08-10 16:35:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/Regression/C/20000605-2.c

struct F { int i; };

void f1(struct F *x, struct F *y)
{
  int timeout = 0;
  for (; ((const struct F*)x)->i < y->i ; x->i++)
    if (++timeout > 5)
      abort ();
}

int main()
{
  struct F x, y;
  x.i = 0;
  y.i = 1;
  f1 (&x, &y);
  exit (0);
}
