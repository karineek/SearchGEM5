
// Modification timestamp: 2023-08-10 16:10:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/Programs/SingleSource/UnitTests/sumarraymalloc.c

#include <stdlib.h>
#include <stdio.h>

#define SIZE 100

static int SumArray(int *Array, unsigned Num) {
  int Result = 0;
  unsigned i;
  for (i = 0; i < Num; ++i)
    Result += Array[i];

  return Result;
}

static int SumArray2(int *Array, unsigned Num) {
  int Result = 0;
  unsigned i;
  for (i = 0; i < Num; ++i)
    Result += *Array++;

  return Result;
}

static void FillArray(int *Array, unsigned Num) {
  unsigned i;
  for (i = 0; i < Num; ++i)
    Array[i] = i;
}

int main() {
  int size;
  int *MyArray;

  size = SIZE;
  MyArray = malloc(sizeof(int)* size);

  FillArray(MyArray, size);
  printf("Sum1 = %d\n", SumArray(MyArray, SIZE));
  printf("Sum2 = %d\n", SumArray2(MyArray, SIZE));
  free(MyArray);
  return 0;
}
