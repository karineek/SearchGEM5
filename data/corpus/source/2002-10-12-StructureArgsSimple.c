// Modification timestamp: 2023-08-14 17:11:54
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-10-12-StructureArgsSimple.c

#include <stdio.h>
#include <stdlib.h>

struct vec2 {
  double X, Y;
};

void print(struct vec2 S) {
  printf("%f, %f\n", S.X, S.Y);
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <X> <Y>\n", argv[0]);
    return 1;
  }

  struct vec2 U;
  U.X = atof(argv[1]);
  U.Y = atof(argv[2]);
  print(U);
  return 0;
}

