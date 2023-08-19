// Modification timestamp: 2023-08-14 14:21:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/cvt-1.c

#include <stdio.h>
#include <stdlib.h>

static inline long g1(double x) {
  return (double)(long)x;
}

long g2(double f) {
  return f;
}

double f(long i) {
  if (g1(i) != g2(i))
    abort();
  return g2(i);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long arg = atol(argv[1]);

  if (f(arg) != arg)
    abort();
  if (f(arg) != g2(arg))
    abort();

  return 0;
}
