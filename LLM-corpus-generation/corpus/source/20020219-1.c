// Modification timestamp: 2023-08-14 12:10:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020219-1.c

#include <stdio.h>
#include <stdlib.h>

long long foo(long long C, int Y) {
  long long X;
  X = C >> (Y & 31);
  return X;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <C> <Y>\n", argv[0]);
    return 1;
  }

  long long C = atoll(argv[1]);
  int Y = atoi(argv[2]);

  if (foo(C, Y) != (1ULL << 63)) {
    abort();
  }
  exit(0);
}
