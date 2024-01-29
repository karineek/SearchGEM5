// Modification timestamp: 2023-08-14 14:32:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-8.c

#include <stdio.h>
#include <stdlib.h>

double a[3] = { 0.0, 1.0, 2.0 };

void bar (int x, double *y)
{
  if (x || *y != 1.0)
    abort ();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  double c = atof(argv[1]);
  int d;
  for (d = 0; d < 3; d++)
  {
    c = a[d];
    if (c > 0.0) goto e;
  }
  bar(1, &c);
  exit (1);
e:
  bar(0, &c);
  exit (0);
}
