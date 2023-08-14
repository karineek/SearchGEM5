// Modification timestamp: 2023-08-14 11:53:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001108-1.c

#include <stdio.h>
#include <stdlib.h>

long long signed_poly(long long sum, long x) {
  sum += (long long)(long)sum * (long long)x;
  return sum;
}

unsigned long long unsigned_poly(unsigned long long sum, unsigned long x) {
  sum += (unsigned long long)(unsigned long)sum * (unsigned long long)x;
  return sum;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long long arg1 = atoll(argv[1]);
  long arg2 = atol(argv[2]);

  if (signed_poly(arg1, arg2) != -4LL) {
    abort();
  }

  if (unsigned_poly(arg1, arg2) != 8ULL) {
    abort();
  }

  exit(0);
}
