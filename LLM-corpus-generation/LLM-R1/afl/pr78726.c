// Modification timestamp: 2023-08-14 15:53:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78726.c

#include <stdio.h>
#include <stdlib.h>

unsigned char b = 36, c = 173;
unsigned int d;

__attribute__((noinline, noclone)) void foo(unsigned char *p_b, unsigned char *p_c, unsigned int *p_d) {
  unsigned a = ~(*p_b);
  *p_d = a * (*p_c) * (*p_c) + 1023094746U * a;
}

int main(int argc, char *argv[]) {
  if (__SIZEOF_INT__ != 4 || __CHAR_BIT__ != 8)
    return 0;
  asm volatile ("" : : "g" (&b), "g" (&c) : "memory");
  foo(&b, &c, &d);
  if (d != 799092689U)
    __builtin_abort ();
  return 0;
}
