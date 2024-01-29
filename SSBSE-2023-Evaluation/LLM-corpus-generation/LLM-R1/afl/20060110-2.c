// Modification timestamp: 2023-08-14 13:06:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060110-2.c

#include <stdio.h>
#include <stdlib.h>

long long f(long long a, long long b) {
  return ((a + b) << 32) >> 32;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  long long a = atoll(argv[1]);
  long long b = atoll(argv[2]);
  long long c = ((a + b) << 32) >> 32;

  if (f(a, b) != c)
    abort();

  return 0;
}
