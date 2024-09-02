// Modification timestamp: 2023-08-14 14:25:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/divconst-2.c

#include <stdio.h>
#include <stdlib.h>

long f(long x) {
  return x / (-0x7fffffffL - 1L);
}

long r(long x) {
  return x % (-0x7fffffffL - 1L);
}

long std_eqn(long num, long denom, long quot, long rem) {
  return quot * (-0x7fffffffL - 1L) + rem == num;
}

int main(int argc, char *argv[]) {
  long nums[] = {
    -1L, 0x7fffffffL, -0x7fffffffL - 1L
  };

  for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
    if (std_eqn(nums[i], -0x7fffffffL - 1L, f(nums[i]), r(nums[i])) == 0) {
      abort();
    }
  }

  exit(0);
}
