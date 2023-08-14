// Modification timestamp: 2023-08-14 13:45:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960317-1.c

#include <stdio.h>
#include <stdlib.h>

int f(unsigned bitcount, int mant) {
  int mask = -1 << bitcount;

  if (!(mant & -mask)) {
    goto ab;
  }
  if (mant & ~mask) {
    goto auf;
  }

ab:
  return 0;

auf:
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <bitcount> <mantissa>\n", argv[0]);
    return 1;
  }

  unsigned bitcount = atoi(argv[1]);
  int mant = atoi(argv[2]);

  if (f(bitcount, mant)) {
    abort();
  }
  exit(0);
}

