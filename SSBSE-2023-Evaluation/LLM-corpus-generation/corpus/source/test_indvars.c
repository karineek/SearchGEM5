// Modification timestamp: 2023-08-14 17:36:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//test_indvars.c
#include <stdlib.h>


#include <stdio.h>

static void test_indvars(int *Array1, int Array2[100][200]) {
  unsigned i, j;
  Array1[1] = Array2[3][6] = 12345;

  int step1 = 0;
  for (i = 0; i < 100; i+=2) {
    Array1[i] = i + step1;
    step1 += 2;           /* Step by non unit amount */
  }

  int offset = 0;
  for (i = 3; i < 103; i++) {
    Array1[i] = i + 4 + offset;
    offset++;         /* Step with an offset */
  }

  for (i = 13; i < 100; i++) {
    for (j = 0; j < 100; j+=3) {       /* 2d array access */
      Array2[i][j/3] = Array2[i][i];
    }
  }
}


int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  int Array[100][200], i, j;
  double sum = 0.0;

  for (i=0; i < 100; i+=2) {
    for (j=0; j < 200; j++) {
      Array[i][j] = 0;
    }
  }
  test_indvars(Array[0], Array);

  for (i=0; i < 100; i+=2) {
    for (j=0; j < 200; j++) {
      sum += Array[i][j];
    }
  }

  printf("Checksum = %.0lf\n", sum);

  return 0;
}
