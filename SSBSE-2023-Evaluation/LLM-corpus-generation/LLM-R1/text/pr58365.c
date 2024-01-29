// Modification timestamp: 2023-08-14 15:30:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58365.c
/* PR rtl-optimization/58365 */

extern void abort (void);

struct S
{
  volatile int a;
  int b, c, d, e;
} f;
static struct S g, h;
int i = 1;

char
foo (void)
{
  return i;
}

static struct S
bar (void)
{
  if (foo ())
    return f;
  return g;
}

int
main ()
{
  h = bar ();
  f.b = 1;
  if (h.b != 0)
    abort ();
  return 0;
}
