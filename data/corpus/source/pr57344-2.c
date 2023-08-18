// Modification timestamp: 2023-08-14 15:28:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57344-2.c

#include <stdio.h>
#include <stdlib.h>

struct __attribute__((packed)) S {
  int a : 27;
#if __SIZEOF_INT__ * __CHAR_BIT__ >= 32
  int b : 22;
#else
  int b : 13;
#endif
  char c;
  int : 0;
} s[2];
int i;

__attribute__((noinline, noclone)) void foo(int x) {
  if (x != -3161) {
    printf("Error: x is not -3161\n");
    exit(1);
  }
  asm volatile ("" : : : "memory");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct S t = { 0, atoi(argv[1]) };
  s[1] = t;

  for (; i < 1; i++)
    foo(s[1].b);

  return 0;
}
