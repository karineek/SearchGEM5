// Modification timestamp: 2023-08-14 15:27:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57131.c

#include <stdio.h>
#include <stdlib.h>

void checkResult(long long result) {
  if (result != 1) {
    abort();
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x1 = atoi(argv[1]);
  long long x2 = atol(argv[2]);
  int x3 = atoi(argv[3]);
  int x4 = atoi(argv[4]);
  int x5 = atoi(argv[5]);
  long long x6 = atol(argv[6]);

  long long t = ((x1 * (x2 << x3)) / (x4 * x5)) + x6;
  checkResult(t);

  return 0;
}

