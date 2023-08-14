// Modification timestamp: 2023-08-14 12:06:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011019-1.c
extern void exit (int);
extern void abort (void);

struct { int a; int b[5]; } x;
int *y;

int foo (void)
{
  return y - x.b;
}

int main (void)
{
  y = x.b;
  if (foo ())
    abort ();
  exit (0);
}
