// Modification timestamp: 2023-08-14 15:35:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58831.c

#include <stdio.h>
#include <assert.h>

int a, *b, c, d, f, **i, p, q, *r;
short o, j;

static int __attribute__((noinline, noclone))
fn1 (int *p1, int **p2)
{
  int **e = &b;
  for (; p; p++)
    {
      *p1 = atoi(argv[1]);
    }
  *e = *p2 = &d;

  assert (r);

  return c;
}

static int ** __attribute__((noinline, noclone))
fn2 (void)
{
  for (f = 0; f != 42; f++)
    {
      int *g[3] = {0, 0, 0};
      for (o = 0; o; o--)
        for (; a > 1;)
          {
            int **h[1] = { &g[2] };
          }
    }
  return &r;
}

int
main (int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  i = fn2 ();
  fn1 (b, i);
  return 0;
}
