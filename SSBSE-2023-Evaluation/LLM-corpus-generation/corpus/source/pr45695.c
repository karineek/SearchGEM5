// Modification timestamp: 2023-08-14 15:14:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr45695.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

__attribute__((noinline)) void g(int x) {
  asm volatile("" : "+r"(x));
}

__attribute__((noinline)) int f(int a, int b, int d) {
  int r = -1;
  b += d;
  if (d == a)
    r = b - d;
  g(b);
  return r;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int l = atoi(argv[1]);
  int arg0 = l + 0;
  int arg1 = l + 1;
  int arg2 = l + 4;

  int result1 = f(arg0, arg1, arg2);
  if (result1 != -1)
    abort();

  int arg3 = l + 4;
  int result2 = f(arg3, arg1, arg2);
  if (result2 != 1)
    abort();

  return 0;
}
