// Modification timestamp: 2023-08-14 15:22:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr52129.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
struct S {
  void *p;
  unsigned int q;
};
struct T {
  char a[64];
  char b[64];
} t;

__attribute__((noinline, noclone)) int foo(void *x, struct S s, void *y, void *z) {
  if (x != &t.a[2] || s.p != &t.b[5] || s.q != 27 || y != &t.a[17] || z != &t.b[17])
    abort();
  return 29;
}

__attribute__((noinline, noclone)) int bar(void *x, void *y, void *z, struct S s, int t, struct T *u) {
  return foo(x, s, &u->a[t], &u->b[t]);
}

int main(int argc, char *argv[]) {
  struct S s = {&t.b[5], 27};
  if (bar(&t.a[2], NULL, NULL, s, 17, &t) != 29)
    abort();
  return 0;
}
