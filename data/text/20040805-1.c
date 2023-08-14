// Modification timestamp: 2023-08-14 12:58:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040805-1.c
/* { dg-require-stack-size "0x12000" } */

#if __INT_MAX__ < 32768
int main () { exit (0); }
#else
int a[2] = { 2, 3 };

static int __attribute__((noinline))
bar (int x, void *b)
{
  a[0]++;
  return x;
}

static int __attribute__((noinline))
foo (int x)
{
  char buf[0x10000];
  int y = a[0];
  a[1] = y;
  x = bar (x, buf);
  y = bar (y, buf);
  return x + y;
}

int
main ()
{
  if (foo (100) != 102)
    abort ();
  exit (0);
}
#endif
