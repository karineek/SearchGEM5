// Modification timestamp: 2023-08-14 16:06:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pta-field-2.c

#include <stdio.h>
#include <stdlib.h>

struct Foo {
  int *p;
  int *q;
};

void __attribute__((noinline))
bar(int **x, int *p, int *q)
{
  struct Foo *f = (struct Foo *)(x - 1);
  *(f->p) = *p;
}

int foo(int *p, int *q)
{
  struct Foo f;
  int i = *p, j = *q;
  f.p = &i;
  f.q = &j;
  bar(&f.q, p, q);
  return i;
}

extern void abort(void);

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int p = atoi(argv[1]);
  int q = atoi(argv[2]);

  if (foo(&p, &q) != 0)
    abort();

  return 0;
}
