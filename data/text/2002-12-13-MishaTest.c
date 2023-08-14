
// Modification timestamp: 2023-08-10 14:45:19
// Original Source: https://github.com/llvm/llvm-test-suite

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
