// Modification timestamp: 2023-08-14 15:41:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr64255.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) void bar(long i, unsigned long j) {
  if (i != 1 || j != 1)
    __builtin_abort();
}

__attribute__((noinline, noclone)) void foo(long i) {
  unsigned long j;

  if (!i)
    return;
  j = i >= 0 ? (unsigned long)i : -(unsigned long)i;
  if ((i >= 0 ? (unsigned long)i : -(unsigned long)i) != j)
    __builtin_abort();
  bar(i, j);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long i = atoi(argv[1]);

  foo(i);
  return 0;
}
