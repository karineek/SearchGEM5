
// Modification timestamp: 2023-08-10 15:53:50
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Applications/obsequi/2003-05-22-VarSizeArray.c

#include <stdio.h>

int test(int Num) {
  int Arr[Num];
  Arr[2] = 0;
  return Arr[2];
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int Num = atoi(argv[1]);
  printf("%d\n", test(Num));
  return 0;
}
