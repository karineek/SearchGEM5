// Modification timestamp: 2023-08-14 13:22:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20141125-1.c

#include <stdio.h>
#include <stdlib.h>

int f(long long a) __attribute__((noinline,noclone));
int f(long long a)
{
  if (a & 0x3ffffffffffffffull)
    return 1;
  return 1024;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long long arg1 = strtoll(argv[1], NULL, 0);

  if(f(arg1) != 1)
    abort();
  if (f(0xfc00000000000000ull) != 1024)
    abort();
  return 0;
}
