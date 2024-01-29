// Modification timestamp: 2023-08-14 14:28:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/index-1.c

#include <stdio.h>
#include <stdlib.h>

int a[] =
{
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
  10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
  20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
  30, 31, 32, 33, 34, 35, 36, 37, 38, 39
};

int f(long n)
{
  return a[n - atoi(argv[1])];
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (f(atoi(argv[2])) != 30)
    abort();
  exit(0);
}

Please note that in the `f` function, `n` is replaced with `argv[2]` as it represents the argument passed to the function `f`.