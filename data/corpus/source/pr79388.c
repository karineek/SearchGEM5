// Modification timestamp: 2023-08-14 15:54:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr79388.c

#include <stdio.h>
#include <stdlib.h>

unsigned int a, c;

__attribute__ ((noinline, noclone)) unsigned int
foo (unsigned int p)
{
  p |= 1;
  p &= 0xfffe;
  p %= 0xffff;
  c = p;
  return a + p;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int p = atoi(argv[1]);
  unsigned int x = foo(p);

  if (x != p) {
    __builtin_abort();
  }
  
  return 0;
}
