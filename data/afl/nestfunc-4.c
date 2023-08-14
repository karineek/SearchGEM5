// Modification timestamp: 2023-08-14 14:41:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/nestfunc-4.c

#include <stdio.h>
#include <stdlib.h>

long level = 0;
extern long foo (long tmp);
extern long bar (long tmp);

#ifdef STACK_SIZE
#define DEPTH ((STACK_SIZE) / 512 + 1)
#else
#define DEPTH 500
#endif

int main(void) {
  if (foo(0) == -42) exit(0);
  abort();
}

long foo(long tmp) {
  tmp = ++level;
  return bar(tmp) + tmp;
}

long bar(long tmp) {
  tmp = level;
  return tmp > DEPTH - 1 ? -42 - tmp : foo(tmp) - tmp;
}
