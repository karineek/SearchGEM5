// Modification timestamp: 2023-08-14 15:49:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70222-1.c

#include <stdio.h>
#include <stdlib.h>

int a = 1;
unsigned int b = 2;
int c = 0;
int d = 0;

void foo()
{
  int e = ((-(c >= c)) < b) > ((int)(-1ULL >> ((a / a) * 15)));
  d = -e;
}

__attribute__((noinline, noclone)) void bar(int x)
{
  if (x != -1)
    __builtin_abort();
}

int main(int argc, char *argv[])
{
#if __CHAR_BIT__ == 8 && __SIZEOF_INT__ == 4 && __SIZEOF_LONG_LONG__ == 8
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  foo();
  bar(x);
#endif
  return 0;
}
