// Modification timestamp: 2023-08-14 17:30:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/testcase-ExprConstant-2.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i = 0;
  printf("%s\n", _Generic(i + (2L + 42), long
                          : "long", int
                          : "int", long long
                          : "long long"));
  return 0;
}
