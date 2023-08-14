// Modification timestamp: 2023-08-14 13:32:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921202-2.c

#include <stdio.h>
#include <stdlib.h>

int f(long long x)
{
  x >>= 8;
  return x & 0xff;
}

int main(int argc, char *argv[]) {
  if (f(atoll(argv[1])) != atoi(argv[2])) {
    abort();
  }
  exit(0);
}
