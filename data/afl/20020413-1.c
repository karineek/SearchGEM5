// Modification timestamp: 2023-08-14 12:15:33
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020413-1.c

#include <stdio.h>
#include <stdlib.h>

void test(double val, int *eval) {
  double tmp = 1.0;
  int i = 0;

  if (val < 0.0)
    val = -val;

  if (val >= tmp)
    while (tmp < val) {
      tmp *= 2.0;
      if (i++ >= 10)
        abort();
    }
  else if (val != 0.0)
    while (val < tmp) {
      tmp /= 2.0;
      if (i++ >= 10)
        abort();
    }

  *eval = i;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int eval;

  test(atof(argv[1]), &eval);
  test(atof(argv[2]), &eval);
  test(atof(argv[3]), &eval);
  test(atof(argv[4]), &eval);
  exit(0);
}

