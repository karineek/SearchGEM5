// Modification timestamp: 2023-08-14 17:28:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/conditional-gnu-ext.c

#include <stdio.h>
#include <stdlib.h>

extern void abort();

_Complex int getComplex(_Complex int val) {
  static int count;
  if (count++)
    abort();
  return val;
}

_Complex int doo(_Complex int rhs) {
    _Complex int cond;

    return getComplex(1+2i) ? : rhs;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <real> <imaginary>\n", argv[0]);
    return 1;
  }

  _Complex int rhs = atoi(argv[2]) + atoi(argv[3]) * I;
  doo(rhs);
  return 0;
}
