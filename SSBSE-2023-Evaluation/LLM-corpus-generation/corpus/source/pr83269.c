// Modification timestamp: 2023-08-14 15:59:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr83269.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
#if __SIZEOF_INT__ == 4 && __SIZEOF_LONG_LONG__ > 4 && __CHAR_BIT__ == 8
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  volatile unsigned char a = atoi(argv[1]);
  long long b = 0x80000000L;
  int c = -((int)(-b) - (-0x7fffffff * a));
  if (c != 1)
    __builtin_abort ();
#endif
  return 0;
}
