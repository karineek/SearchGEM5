// Modification timestamp: 2023-08-14 17:12:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-05-12-MinIntProblem.c
#include <stdio.h>

void foo(int X) {
  if (X+1 < 0)
    printf("success\n");
}
int main() {
 foo(-2147483648);
 return 0;
}

