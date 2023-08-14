// Modification timestamp: 2023-08-14 16:06:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pta-field-1.c

#include <stdio.h>
#include <stdlib.h>

struct Foo {
  int *p;
  int *q;
};

void __attribute__((noinline))
bar (int **x)
{
  struct Foo *f = (struct Foo *)x;
  *(f->q) = 0;
}

int foo(int *args)
{
  struct Foo f;
  int i = args[0], j = args[1];
  f.p = &i;
  f.q = &j;
  bar(&f.p);
  return j;
}

extern void abort (void);

int main(int argc, char *argv[])
{
  if (argc < 3) {
    printf("Usage: %s <value_1> <value_2>\n", argv[0]);
    return 1;
  }

  int args[2];
  args[0] = atoi(argv[1]);
  args[1] = atoi(argv[2]);

  if (foo(args) != 0)
    abort ();
  return 0;
}
