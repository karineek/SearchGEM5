// Modification timestamp: 2023-08-14 12:06:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011019-1.c

#include <stdio.h>
#include <stdlib.h>

extern void exit(int);
extern void abort(void);

struct {
  int a;
  int b[5];
} x;

int *y;

int foo(int *y, int *x_b) {
  return y - x_b;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x_b[5];
  y = x_b;
  if (foo(y, x_b)) {
    abort();
  }
  exit(0);
}
