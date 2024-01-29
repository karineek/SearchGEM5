// Modification timestamp: 2023-08-14 14:40:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/nest-align-1.c

#include <stddef.h>
#include <stdio.h>

typedef int aligned __attribute__((aligned));
extern void abort (void);

void check(int *i) {
  *i = 20;
  if ((((ptrdiff_t)i) & (__alignof__(aligned) - 1)) != 0)
    abort();
}

void bar(aligned *j) {
  *j = -20;
}

void foo() {
  aligned jj;
  jj = 0;
  bar(&jj);
  if (jj != -20)
    abort();
  check(&jj);
  if (jj != 20)
    abort();
}

int main(int argc, char *argv[]) {
  foo();
  return 0;
}
