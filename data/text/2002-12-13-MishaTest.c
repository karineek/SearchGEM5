// Modification timestamp: 2023-08-14 17:12:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-12-13-MishaTest.c

#include <stdio.h>
sum(to, from, count)
     short *to, *from;
     short count;
{
  int i;
  for (i = 0; i != count; ++i)
    *to += *from++;
}

#define NUM 2
int main() {
  short Array[NUM];
  short Sum = 0;
  int i;

  for (i = 0; i != NUM; ++i)
    Array[i] = i;

  sum(&Sum, Array, NUM);

  printf("Sum is %d\n", Sum);
  return 0;
}
