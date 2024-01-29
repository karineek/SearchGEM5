// Modification timestamp: 2023-08-14 17:32:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-05-22-VarSizeArray.c


#include <stdio.h>
#include <stdlib.h>

int test(int Num) {
  int Arr[Num];
  Arr[atoi(argv[2])] = atoi(argv[3]);
  return Arr[atoi(argv[2])];
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <Num> <index> <value>\n", argv[0]);
    return 1;
  }

  printf("%d\n", test(atoi(argv[1])));
  return 0;
}
