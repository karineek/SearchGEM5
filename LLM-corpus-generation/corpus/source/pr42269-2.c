// Modification timestamp: 2023-08-14 15:09:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42269-2.c
#include <stdio.h>
#include <stdlib.h>

static long long __attribute__((noinline))
foo (unsigned short s)
{
  return (short) s;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned short s = atoi(argv[1]);
  return foo(s) + 1 != 0;
}
