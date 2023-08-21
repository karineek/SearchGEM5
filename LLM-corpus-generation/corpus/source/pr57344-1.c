// Modification timestamp: 2023-08-14 15:28:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57344-1.c

#include <stdio.h>
#include <stdlib.h>

struct __attribute__((packed)) S
{
  int a : 11;
#if __SIZEOF_INT__ * __CHAR_BIT__ >= 32
  int b : 22;
#else
  int b : 13;
#endif
  char c;
  int : 0;
} s[2];

int i;

__attribute__((noinline, noclone)) void foo(int x)
{
  if (x != -3161)
    __builtin_abort();
  asm volatile ("" : : : "memory");
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <arg1> <arg2> <arg3>\n", argv[0]);
    return 1;
  }

  struct S t = {atoi(argv[1]), atoi(argv[2]), *argv[3]};
  s[1] = t;
  for (; i < 1; i++)
    foo(s[1].b);
  return 0;
}
