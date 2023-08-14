// Modification timestamp: 2023-08-14 15:50:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70566.c

#include <stdio.h>
#include <stdlib.h>

#define NULL 0

struct mystruct
{
  unsigned int f1 : 1;
  unsigned int f2 : 1;
  unsigned int f3 : 1;
};

__attribute__ ((noinline)) void myfunc(int a, void *b)
{
}

__attribute__ ((noinline)) int myfunc2(void *a)
{
  return 0;
}

static void set_f2(struct mystruct *user, int f2)
{
  if (user->f2 != f2)
    myfunc(myfunc2(NULL), NULL);
  else
    __builtin_abort();
}

__attribute__ ((noinline)) void foo(void *data)
{
  struct mystruct *user = data;
  if (!user->f2)
    set_f2(user, 1);
}

int main(int argc, char *argv[])
{
  struct mystruct a;
  a.f1 = atoi(argv[1]);
  a.f2 = atoi(argv[2]);
  foo(&a);
  return 0;
}
