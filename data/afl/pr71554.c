// Modification timestamp: 2023-08-14 15:51:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr71554.c

#include <stdio.h>
#include <stdlib.h>

int v;

__attribute__ ((noinline, noclone)) void bar(void) {
  v++;
}

__attribute__ ((noinline, noclone)) void foo(unsigned int x) {
  signed int y = atoi(argv[1]);
  signed int r;
  if (__builtin_mul_overflow (x, y, &r))
    bar();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  foo(2);
  if (v)
    __builtin_abort();
  return 0;
}

Note: Since the value of `y` in the original code is `((-__INT_MAX__ - 1) / 2)`, I have replaced it with `atoi(argv[1])` as an example. The actual value should be passed as a command-line argument.