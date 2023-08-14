// Modification timestamp: 2023-08-14 13:22:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20140622-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned p;

long __attribute__((noinline, noclone)) test(unsigned a) {
  return (long)(p + a) - (long)p;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  p = (unsigned)atoi(argv[1]);
  if (test(0) != 0)
    abort();
  if (test(1) != 1)
    abort();
  if (test(2) != -(long)(unsigned)atoi(argv[1]))
    abort();
  p = (unsigned)atoi(argv[1]);
  if (test(0) != 0)
    abort();
  if (test(1) != -(long)(unsigned)atoi(argv[1]))
    abort();
  if (test(2) != -(long)(unsigned)atoi(argv[1]))
    abort();

  return 0;
}

Note: The conversion of `p` to `unsigned` is done using `atoi(argv[1])` instead of directly assigning `(unsigned) -2` or `(unsigned) -1` to avoid compiler warnings about signedness.