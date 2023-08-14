// Modification timestamp: 2023-08-14 15:08:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42154.c

#include <stdio.h>
#include <stdlib.h>

struct A { char x[1]; };

extern void abort(void);

void __attribute__((noinline,noclone))
foo(struct A a)
{
  if (a.x[0] != 'a')
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct A a;
  int i;
  for (i = 0; i < 1; ++i)
    a.x[i] = argv[1][i];

  foo(a);

  return 0;
}

