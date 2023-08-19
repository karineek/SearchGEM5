// Modification timestamp: 2023-08-14 15:13:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr44858.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int a;
int b;

__attribute__((noinline)) long long foo(int x, int y) {
  return x / y;
}

__attribute__((noinline)) int bar(int a, int b, int c) {
  c &= foo(1, b) > b;
  b = (a != 0) | c;
  return c;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <a> <b> <c>\n", argv[0]);
    return 1;
  }

  a = atoi(argv[1]);
  b = atoi(argv[2]);
  int c = atoi(argv[3]);

  if (bar(a, b, c) != 0 || b != 1)
    abort();
  return 0;
}
