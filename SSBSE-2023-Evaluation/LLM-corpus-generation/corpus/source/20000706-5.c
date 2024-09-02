
// Modification timestamp: 2023-08-10 16:37:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000706-5.c
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern void abort(void);
extern void exit(int);

struct baz { int a, b, c; };

struct baz *c;

void bar(int b)
{
  if (c->a != 1 || c->b != 2 || c->c != 3 || b != 4)
    abort();
}

void foo(struct baz a, int b)
{
  c = &a;
  bar(b);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct baz a;
  a.a = atoi(argv[1]);
  a.b = 2;
  a.c = 3;
  foo(a, 4);
  exit(0);
}
