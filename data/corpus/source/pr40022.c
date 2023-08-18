// Modification timestamp: 2023-08-14 15:05:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr40022.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

struct A {
  struct A *a;
};

struct B {
  struct A *b;
};

__attribute__((noinline)) struct A *foo(struct A *x) {
  asm volatile("" : : "g"(x) : "memory");
  return x;
}

__attribute__((noinline)) void bar(struct B *w, struct A *x, struct A *y, struct A *z) {
  struct A **c;
  c = &(w->b);
  *c = foo(x);
  while (*c)
    c = &((*c)->a);
  *c = foo(y);
  while (*c)
    c = &((*c)->a);
  *c = foo(z);
}

struct B d;
struct A e, f, g;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  f.a = &g;
  bar(&d, &e, &f, atoi(argv[1]));
  if (d.b == 0 || d.b->a == 0 || d.b->a->a == 0 || d.b->a->a->a != 0)
    abort();
  return 0;
}
