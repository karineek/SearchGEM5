// Modification timestamp: 2023-08-14 17:17:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2005-05-13-SDivTwo.c
// Check that signed divide by a power of two works for small types
#include <stdio.h>
int main() {
  int i;
  for (i = 0; i != 258; ++i) {
    printf("%d\n", ((signed char)i) / (signed char)2);
  }
  return 0;
}
