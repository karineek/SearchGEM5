// Modification timestamp: 2023-08-14 13:23:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20180226-1.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long mp_digit;
typedef struct { int used, alloc, sign; mp_digit *dp; } mp_int;

int mytest(mp_int *a, mp_digit b) __attribute__((noclone, noinline));

int mytest(mp_int *a, mp_digit b)
{
  if (a->sign == 1)
    return -1;
  if (a->used > 1)
    return 1;
  if (a->dp[0] > b)
    return 1;
  if (a->dp[0] < b)
    return -1;
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  mp_int i = { 2, 0, -1 };
  int result = mytest(&i, atoi(argv[1]));

  if (result != 1)
    abort();
  
  return 0;
}
