// Modification timestamp: 2023-08-14 15:45:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr66940.c
#include <stdlib.h>

#include <stdio.h>

long long foo(long long ival)
{
  if (ival <= 0)
    return -0x7fffffffffffffffL - 1;

  return 0x7fffffffffffffffL;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long long arg1 = atoll(argv[1]);

  if (foo(arg1) != (-0x7fffffffffffffffL - 1))
    __builtin_abort();

  if (foo(arg1) != 0x7fffffffffffffffL)
    __builtin_abort();

  return 0;
}
