
// Modification timestamp: 2023-08-10 15:09:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/test/CodeGen/2004-06-20-StaticBitfieldInit.c

#include <stdio.h>
#include <stdlib.h>

struct T {
  unsigned X : 5;
  unsigned Y : 6;
  unsigned Z : 5;
};

struct T GV;

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <X> <Y> <Z>\n", argv[0]);
    return 1;
  }

  GV.X = atoi(argv[1]);
  GV.Y = atoi(argv[2]);
  GV.Z = atoi(argv[3]);

  printf("%d %d %d\n", GV.X, GV.Y, GV.Z);
  return 0;
}
