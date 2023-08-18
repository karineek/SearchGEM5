// Modification timestamp: 2023-08-14 14:25:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/divconst-3.c

#include <stdio.h>
#include <stdlib.h>

long long f(long long x) {
  return x / 10000000000LL;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long long result1 = f(atoll(argv[1]));
  long long result2 = f(atoll(argv[2]));

  if (result1 != 1 || result2 != 10) {
    abort();
  }

  exit(0);
}
