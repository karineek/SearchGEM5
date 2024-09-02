// Modification timestamp: 2023-08-14 17:32:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-05-21-UnionTest.c
#include <stdio.h>

int __signbit (double __x) {
  union { double __d; int __i[3]; } __u = { __d: __x };
  return __u.__i[1] < 0;
}

int main() {
  printf("%d %d\n", __signbit(-1), __signbit(2.0));
  return 0;
}
