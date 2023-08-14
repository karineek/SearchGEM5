// Modification timestamp: 2023-08-14 17:32:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-10-12-GlobalVarInitializers.c
#include <stdio.h>

union { unsigned __l; float __d; } GlobalUnion = { 0x70c00000U };

int main() {
  union { unsigned __l; float __d; } LocalUnion = { 0x7fc00000U };

  printf("%f %f\n", GlobalUnion.__d, LocalUnion.__d);

  return 0;
}



