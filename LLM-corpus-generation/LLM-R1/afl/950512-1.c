// Modification timestamp: 2023-08-14 13:41:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950512-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned f1(unsigned x) {
  return ((unsigned) (x != 0) - 3) / 2;
}

unsigned long long f2(unsigned long long x) {
  return ((unsigned long long) (x != 0) - 3) / 2;
}

int main(int argc, char *argv[]) {
  if (f1(1) != (~(unsigned) 0) >> 1)
    abort();
  if (f1(0) != ((~(unsigned) 0) >> 1) - 1)
    abort();
  if (f2(1) != (~(unsigned long long) 0) >> 1)
    abort();
  if (f2(0) != ((~(unsigned long long) 0) >> 1) - 1)
    abort();
  exit(0);
}
