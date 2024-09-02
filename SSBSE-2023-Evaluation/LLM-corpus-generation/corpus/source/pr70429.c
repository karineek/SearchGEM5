// Modification timestamp: 2023-08-14 15:50:11
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70429.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) int
foo (int a)
{
  return (int) (0x14ff6e2207db5d1fLL >> a) >> 4;
}

int
main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (sizeof(int) != 4 || sizeof(long long) != 8 || __CHAR_BIT__ != 8)
    return 0;
  if (foo(atoi(argv[1])) != 0x3edae8 || foo(atoi(argv[2])) != -132158092)
    abort();
  return 0;
}
