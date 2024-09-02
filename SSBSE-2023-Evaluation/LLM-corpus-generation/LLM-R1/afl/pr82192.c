// Modification timestamp: 2023-08-14 15:57:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr82192.c

#include <stdio.h>
#include <stdlib.h>

unsigned long long int a = 0x95dd3d896f7422e2ULL;
struct S { unsigned int m : 13; } b;

__attribute__((noinline, noclone)) void foo(unsigned long long int arg1, unsigned int arg2)
{
  b.m = ((unsigned) arg1) >> (arg2 | arg1 & ~0xdee27af8U) - 0x644eee9667763bd8LL;
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <arg1> <arg2>\n", argv[0]);
    return 1;
  }

  unsigned long long int a = strtoull(argv[1], NULL, 0);
  unsigned int b = strtoul(argv[2], NULL, 0);

  if (__INT_MAX__ != 0x7fffffffULL)
    return 0;
  foo(a, b);
  if (b.m != 0)
    __builtin_abort ();
  return 0;
}
