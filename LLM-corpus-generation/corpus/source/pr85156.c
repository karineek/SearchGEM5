// Modification timestamp: 2023-08-14 16:00:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr85156.c

#include <stdio.h>
#include <stdlib.h>

int x, y;

__attribute__((noipa)) int
foo (int z)
{
  if (__builtin_expect (x ? y != 0 : 0, z++))
    return 7;
  return z;
}

int
main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  x = atoi(argv[1]);
  asm volatile ("" : "+m" (x), "+m" (y));
  if (foo(atoi(argv[2])) != atoi(argv[3]))
    __builtin_abort();
  return 0;
}
