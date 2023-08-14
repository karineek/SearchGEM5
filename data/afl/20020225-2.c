// Modification timestamp: 2023-08-14 12:10:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020225-2.c

#include <stdio.h>
#include <stdlib.h>

static int test(int x, int a_i) {
  union {
    int i;
    double d;
  } a;
  a.d = 0;
  a.i = a_i;
  return x >> a.i;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int a_i = atoi(argv[2]);
  if (test(x, a_i) != 2)
    abort();

  exit(0);
}

Note: You need to provide the values for `x` and `a_i` as command-line arguments when running the program.