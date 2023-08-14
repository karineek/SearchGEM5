// Modification timestamp: 2023-08-14 13:06:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20060110-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

long long f(long long a) {
  return (a << 32) >> 32;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value> <value>\n", argv[0]);
    return 1;
  }

  long long a = atoll(argv[1]);
  long long b = atoll(argv[2]);

  if (f(a) != b) {
    abort();
  }

  return 0;
}
