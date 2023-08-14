// Modification timestamp: 2023-08-14 13:04:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050613-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

struct A { int i; int j; int k; int l; };
struct B { struct A a; int r[1]; };
struct C { struct A a; int r[0]; };
struct D { struct A a; int r[]; };

void foo(struct A *x)
{
  if (x->i != 0 || x->j != 5 || x->k != 0 || x->l != 0)
    abort();
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  struct B b = { .a.j = atoi(argv[1]) };
  struct C c = { .a.j = atoi(argv[2]) };
  struct D d = { .a.j = atoi(argv[3]) };
  foo(&b.a);
  foo(&c.a);
  foo(&d.a);
  return 0;
}
