
// Modification timestamp: 2023-08-10 15:09:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/test/CodeGen/2004-06-20-StaticBitfieldInit.c

#include <stdio.h>

struct T {
  unsigned X : 5;
  unsigned Y : 6;
  unsigned Z : 5;
};

struct T GV = { 1, 5, 1 };

int main() {
  printf("%d %d %d\n", GV.X, GV.Y, GV.Z);
  return 0;
}
