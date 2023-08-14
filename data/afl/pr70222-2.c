// Modification timestamp: 2023-08-14 15:50:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70222-2.c

#include <stdio.h>
#include <stdlib.h>

#if __CHAR_BIT__ == 8 && __SIZEOF_INT__ == 4 && __SIZEOF_LONG_LONG__ == 8
__attribute__((noinline, noclone)) unsigned int
foo (int x)
{
  unsigned long long y = -1ULL >> x;
  return (unsigned int) y >> 31;
}
#endif

int main(int argc, char *argv[]) {
#if __CHAR_BIT__ == 8 && __SIZEOF_INT__ == 4 && __SIZEOF_LONG_LONG__ == 8
  if (foo(atoi(argv[1])) != 1 || foo(atoi(argv[2])) != 1 || foo(atoi(argv[3])) != 0)
    __builtin_abort();
#endif
  return 0;
}
