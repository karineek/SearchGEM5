// Modification timestamp: 2023-08-14 15:35:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr59014-2.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) long long int foo(long long int x, long long int y) {
  if (((int)x | (int)y) != 0)
    return 6;
  return x + y;
}

int main(int argc, char *argv[]) {
  if (sizeof(long long) == sizeof(int)) {
    printf("Size of long long is equal to size of int\n");
    return 0;
  }

  int shift_half = sizeof(int) * __CHAR_BIT__ / 2;
  long long int x = (3LL << shift_half) << shift_half;
  long long int y = (5LL << shift_half) << shift_half;
  long long int z = foo(x, y);
  if (z != ((8LL << shift_half) << shift_half)) {
    printf("Incorrect result: z = %lld\n", z);
    return 1;
  }

  return 0;
}
