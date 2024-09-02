// Modification timestamp: 2023-08-14 13:52:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990127-2.c

#include <stdio.h>
#include <stdlib.h>

void abort(void) {
  fprintf(stderr, "abort called\n");
  exit(1);
}

void exit(int code) {
  printf("exit called with code %d\n", code);
  exit(code);
}

void fpEq(double x, double y) {
  if (x != y)
    abort();
}

void fpTest(double x, double y) {
  if (argc != 2) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  double result1 = (35.7 * 100.0) / 45.0;
  double result2 = (x * 100.0) / y;
  fpEq(result1, result2);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  double x = atof(argv[1]);
  double y = atof(argv[2]);
  fpTest(x, y);
  exit(0);
}

Note that this conversion requires two additional command line arguments for `x` and `y` values.