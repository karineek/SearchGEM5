// Modification timestamp: 2023-08-14 14:40:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/multdi-1.c

#include <stdio.h>
#include <stdlib.h>

#define u_l_l unsigned long long
#define l_l long long

l_l mpy_res;

u_l_l mpy (long a, long b)
{
  return (u_l_l) a * (u_l_l) b;
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <a> <b>\n", argv[0]);
    return 1;
  }

  long a = atoi(argv[1]);
  long b = atoi(argv[2]);

  mpy_res = mpy(a, b);
  if (mpy_res != -1LL)
    abort ();
  return 0;
}
