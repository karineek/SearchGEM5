// Modification timestamp: 2023-08-14 17:36:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//sumarraymalloc.c
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

int
main(int argc, char** argv)
{
  int size;
  int *MyArray;

  size = (argc < 2)? SIZE : atoi(argv[1]);
  MyArray = malloc(sizeof(int)* size);

  FillArray(MyArray, size);
  printf("Sum1 = %d\n", SumArray(MyArray, SIZE));
  printf("Sum2 = %d\n", SumArray2(MyArray, SIZE));
  free(MyArray);
  return(0);
}
