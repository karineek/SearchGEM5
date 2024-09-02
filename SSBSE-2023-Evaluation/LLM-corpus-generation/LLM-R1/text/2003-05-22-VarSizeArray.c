// Modification timestamp: 2023-08-14 17:32:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-05-22-VarSizeArray.c
#include <stdio.h>

int test(int Num) {
  int Arr[Num];
  Arr[2] = 0;
  return Arr[2];
}

int main() {
  printf("%d\n", test(4));
  return 0;
}
