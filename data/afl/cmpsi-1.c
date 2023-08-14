// Modification timestamp: 2023-08-14 14:14:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/cmpsi-1.c

#include <stdio.h>
#include <stdlib.h>

void dummy() {}

unsigned int f1(unsigned int x, unsigned int y) {
  if (x == 0)
    dummy();
  x -= y;
  if (x < ~(~(unsigned int)0 >> 1))
    abort();
  return x;
}

unsigned long int f2(unsigned long int x, unsigned long int y) {
  if (x == 0)
    dummy();
  x -= y;
  if (x < ~(~(unsigned long int)0 >> 1))
    abort();
  return x;
}

int main(int argc, char *argv[]) {
  unsigned int x1 = ~(unsigned int)0 >> 1;
  unsigned int y1 = ~(~(unsigned int)0 >> 1) + 1;
  f1(x1 - 12, y1);

  unsigned long int x2 = ~(unsigned long int)0 >> 1;
  unsigned long int y2 = ~(~(unsigned long int)0 >> 1) + 1;
  f2(x2 - 12, y2);

  exit(0);
}
