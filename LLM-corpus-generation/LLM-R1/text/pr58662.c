// Modification timestamp: 2023-08-14 15:35:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58662.c
extern void abort (void);

int a, c, d;
volatile int b;

static int
foo (int p1, short p2)
{
  return p1 / p2;
}

int
main ()
{
  char e;
  d = foo (a == 0, (0, 35536));
  e = d % 14;
  b = e && c;
  if (b != 0)
    abort ();
  return 0;
}
