// Modification timestamp: 2023-08-14 17:32:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2003-10-12-GlobalVarInitializers.c

#include <stdio.h>

union { unsigned __l; float __d; } GlobalUnion = { 0x70c00000U };

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  union { unsigned __l; float __d; } LocalUnion = { atof(argv[1]) };

  printf("%f %f\n", GlobalUnion.__d, LocalUnion.__d);

  return 0;
}
