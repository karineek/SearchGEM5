// Modification timestamp: 2023-08-14 17:12:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-04-22-Switch.c

#include <stdio.h>

static int func(unsigned i) {
  int X = 4;
  switch (i) {
  case 8: printf("C\n"); /* fall through. */  X = 6;
  case 0:
  case 3:
  case 2: printf("A\n"); break;
  case 1:
  case 7: X = 7;
  case 9: printf("B\n"); break;
  default: printf("D\n"); X = 1;
  }
  return X;
}


int main() {
  unsigned i;
  for (i = 0; i < 10; ++i)
    func(i);
  return 0;
}
