// Modification timestamp: 2023-08-14 17:22:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2007-01-04-KNR-Args.c

#include <stdio.h>

void p1(char c, float f1, short s, double d1, int i, float f2, long l, double d2) {
  printf("%c %f %d %f %d %f %ld %f\n", c, f1, s, d1, i, f2, l, d2);
}

void p2(char c, float f1, short s, double d1, int i, float f2, long l, double d2) {
  printf("%c %f %d %f %d %f %ld %f\n", c, f1, s, d1, i, f2, l, d2);
}

int main(int argc, char *argv[]) {
  if (argc != 9) {
    printf("Usage: %s <c> <f1> <s> <d1> <i> <f2> <l> <d2>\n", argv[0]);
    return 1;
  }

  char c = argv[1][0];
  float f1 = atof(argv[2]);
  short s = atoi(argv[3]);
  double d1 = atof(argv[4]);
  int i = atoi(argv[5]);
  float f2 = atof(argv[6]);
  long l = atol(argv[7]);
  double d2 = atof(argv[8]);

  p1(c, f1, s, d1, i, f2, l, d2);
  p2(c, f1, s, d1, i, f2, l, d2);

  return 0;
}
