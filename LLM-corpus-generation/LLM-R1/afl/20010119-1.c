// Modification timestamp: 2023-08-14 11:56:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010119-1.c

#include <stdio.h>
#include <stdlib.h>

#ifdef __OPTIMIZE__
extern void undef(void);

void bar(unsigned x) { }
void baz(unsigned x) { }

extern inline void foo(int a, int b)
{
  int c = 0;
  while (c++ < b)
    (__builtin_constant_p(a) ? ((a) > 20000 ? undef() : bar(a)) : baz(a));
}
#else
void foo(int a, int b)
{
}
#endif

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  foo(a, b);
  exit(0);
}
