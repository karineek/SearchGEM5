// Modification timestamp: 2023-08-14 17:36:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//sumarray.c

#include <stdlib.h>
#include <stdio.h>

int SumArray(int Array[], int Num) {
  unsigned i, Result = 0;
  Array[34] = 1234;

  for (i = 0; i < Num; ++i)
    Result += Array[i];

  return Result;
}

int main(int argc, char *argv[]) {
  int *Array = (int*)malloc(sizeof(int)*100);
  int i;

  for (i = 0; i < 100; i += 2)
    Array[i] = i*4;
  for (i = 1; i < 100; i += 2)
    Array[i] = i*2;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int Num = atoi(argv[1]);
  printf("Produced: %d\n", SumArray(Array, Num));
  return 0;
}
