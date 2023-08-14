// Modification timestamp: 2023-08-14 15:07:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr41317.c

#include <stdio.h>
#include <stdlib.h>

struct A
{
  int i;
};

struct B
{
  struct A a;
  int j;
};

static void foo(struct B *p)
{
  ((struct A *)p)->i = 1;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  struct A a;
  a.i = atoi(argv[1]);
  foo((struct B *)&a);
  
  if (a.i != 1)
    abort();
  
  return 0;
}
