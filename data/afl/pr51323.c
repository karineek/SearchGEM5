// Modification timestamp: 2023-08-14 15:19:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr51323.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

struct S { int a, b, c; };

int v;

__attribute__((noinline, noclone)) void foo(int x, int y, int z) {
  if (x != v || y != 0 || z != 9)
    abort();
}

static inline int baz(const struct S *p) {
  return p->b;
}

__attribute__((noinline, noclone)) void bar(int x, struct S y) {
  foo(baz(&y), 0, x);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct S s;
  v = atoi(argv[1]);
  s.a = v - 1;
  s.b = v;
  s.c = v + 1;
  bar(9, s);

  v = atoi(argv[2]);
  s.a = v - 1;
  s.b = v;
  s.c = v + 1;
  bar(9, s);

  return 0;
}

