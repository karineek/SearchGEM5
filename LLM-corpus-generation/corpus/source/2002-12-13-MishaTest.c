// Modification timestamp: 2023-08-14 17:12:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-12-13-MishaTest.c

#include <stdio.h>

void sum(short *to, short *from, short count) {
  int i;
  for (i = 0; i != count; ++i)
    *to += *from++;
}

#define NUM 2
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  short Array[NUM];
  short Sum = 0;
  int i;

  for (i = 0; i != NUM; ++i)
    Array[i] = i;

  sum(&Sum, Array, NUM);

  printf("Sum is %d\n", Sum);
  return 0;
}
