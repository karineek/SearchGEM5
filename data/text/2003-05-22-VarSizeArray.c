
// Modification timestamp: 2023-08-10 15:53:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Applications/obsequi/2003-05-22-VarSizeArray.c

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
