// Modification timestamp: 2023-08-14 14:42:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr15262-2.c

#include <stdio.h>
#include <stdlib.h>

struct A
{
  int t;
  int i;
};

struct B
{
  int *p;
  float b;
};

float X;

float foo(struct B b, struct A *q, float *h)
{
  X += *h;
  *(b.p) = 3;
  q->t = 2;
  return *(b.p);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct A a;
  struct B b;

  b.p = &(a.t);
  if (foo(b, &a, (atof(argv[1]))) == 3)
    abort();

  return 0;
}
