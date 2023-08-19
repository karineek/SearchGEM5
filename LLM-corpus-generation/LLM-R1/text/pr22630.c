// Modification timestamp: 2023-08-14 14:47:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22630.c
void abort (void);

int j;

void bla (int *r)
{
  int *p, *q;

  p = q = r;
  if (!p)
    p = &j;

  if (p != q)
    j = 1;
}

int main (void)
{
  bla (0);
  if (!j)
    abort ();
  return 0;
}
