// Modification timestamp: 2023-08-14 17:14:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-07-06-IntOverflow.c

#include <stdio.h>
#include <stdlib.h>

void compareOvf(int x, int y)
{
  int sum = x * x + y * y;
  if (sum < (1 << 22))
    printf("compare after overflow is TRUE\n");
  else
    printf("compare after overflow is FALSE\n");
}

void divideOvf(int x, int y)
{
  int sum = x * x + y * y;
  int rem = (1 << 31) / sum;
  printf("divide after overflow = %d (0x%x)\n", rem, rem);
}

void divideNeg(int x, int y)
{
  int sum = x * x - y * y;
  int rem = sum / (1 << 18);
  printf("divide negative value by power-of-2 = %d (0x%x)\n", rem, rem);
}

void subtractOvf(int x, int y)
{
  int sum = x * x + y * y;
  int rem = (1u << 31) - sum;
  printf("subtract after overflow = %d (0x%x)\n", rem, rem);
}

int main(int argc, char *argv[]) {
  int b21 = atoi(argv[1]) << 21;
  compareOvf(b21,       b21);
  divideOvf(b21 + 1,    b21 + 2);
  divideNeg(b21 + 1,    b21 + 2);       /* arg1 must be < arg2 */
  subtractOvf(b21 + 1,  b21 + 2);
  return 0;
}
