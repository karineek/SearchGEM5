// Modification timestamp: 2023-08-14 15:03:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr38236.c

#include <stdio.h>

struct X { int i; };

int __attribute__((noinline))
foo (struct X *p, int *q, int a, int b)
{
  struct X x, y;
  if (a)
    p = &x;
  if (b)
    q = &x.i;
  else
    q = &y.i;
  *q = 1;
  return p->i;
}

extern void abort (void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct X x;
  int y;
  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  if (a)
    foo(&x, (void *)0, a, b);
  else
    foo((void *)0, &y, a, b);

  return 0;
}
