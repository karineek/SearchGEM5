// Modification timestamp: 2023-08-14 16:05:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr89634.c

#include <stdio.h>
#include <stdlib.h>

static unsigned long *
foo (unsigned long *x)
{
  return x + (1 + *x);
}

__attribute__((noipa)) unsigned long
bar (unsigned long *x)
{
  unsigned long c, d = 1, e, *f, g, h = 0, i;
  for (e = *x - 1; e > 0; e--)
    {
      f = foo (x + 1);
      for (i = 1; i < e; i++)
        f = foo (f);
      c = *f;
      if (c == 2)
        d *= 2;
      else
        {
          i = (c - 1) / 2 - 1;
          g = (2 * i + 1) * (d + 1) + (2 * d + 1);
          if (g > h)
            h = g;
          d *= c;
        }
    }
  return h;
}

int
main (int argc, char *argv[])
{
  unsigned long a[18] = { atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]), atoi(argv[9]), atoi(argv[10]), atoi(argv[11]), atoi(argv[12]), atoi(argv[13]), atoi(argv[14]), atoi(argv[15]), atoi(argv[16]), atoi(argv[17]), atoi(argv[18]) };
  if (bar (a) != atoi(argv[19]))
    __builtin_abort ();
  return 0;
}
