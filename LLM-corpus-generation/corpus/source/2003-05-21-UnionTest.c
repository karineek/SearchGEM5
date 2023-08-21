// Modification timestamp: 2023-08-14 17:32:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-05-21-UnionTest.c
#include <stdlib.h>

#include <stdio.h>

int __signbit (double __x) {
  union { double __d; int __i[3]; } __u = { __d: __x };
  return __u.__i[1] < 0;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  double val1 = atof(argv[1]);
  double val2 = atof(argv[2]);

  printf("%d %d\n", __signbit(val1), __signbit(val2));
  return 0;
}
