// Modification timestamp: 2023-08-14 17:35:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//compare.c
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int test_1(int ly) __attribute__((noinline));
int test_1(int ly) {
  if (ly <= INT32_MIN)
    ly = INT32_MIN + 1;

  return ly;
}

int test_2(int ly) __attribute__((noinline));
int test_2(int ly) {
  if (INT32_MIN >= ly)
    ly = INT32_MIN + 1;

  return ly;
}

int main () {
  int x = 37;

  printf ("x = %d (0x%x)\n", x, x);

  int r1 = test_1(x);
  printf ("test_1(x) = %d (0x%x)\n", r1, r1);

  int r2 = test_2(x);
  printf ("test_2(x) = %d (0x%x)\n", r2, r2);

  return 0;
}
