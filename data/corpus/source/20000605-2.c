
// Modification timestamp: 2023-08-10 16:35:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/Regression/C/20000605-2.c

#include <stdio.h>
#include <stdlib.h>

struct F { int i; };

void f1(struct F *x, struct F *y)
{
  int timeout = 0;
  for (; ((const struct F*)x)->i < y->i ; x->i++)
    if (++timeout > 5)
      abort ();
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value> <value>\n", argv[0]);
    return 1;
  }

  struct F x, y;
  x.i = atoi(argv[1]);
  y.i = atoi(argv[2]);
  f1 (&x, &y);
  exit (0);
}
