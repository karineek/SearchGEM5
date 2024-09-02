// Modification timestamp: 2023-08-14 13:44:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960215-1.c

#include <stdio.h>
#include <stdlib.h>

long double C, U, Y2, Y1, X, Y, Z, T, R, S;

int main(int argc, char *argv[]) {
  if (argc != 7) {
    printf("Usage: %s <C> <U> <Y2> <Y1> <X> <Y> <Z> <T> <R> <S>\n", argv[0]);
    return 1;
  }

  C = atof(argv[1]);
  U = atof(argv[2]);
  Y2 = atof(argv[3]);
  Y1 = atof(argv[4]);
  X = atof(argv[5]);
  Y = atof(argv[6]);
  Z = atof(argv[7]);
  T = atof(argv[8]);
  R = atof(argv[9]);
  S = atof(argv[10]);

  X = (C + U) * Y2;
  Y = C - U - U;
  Z = C + U + U;
  T = (C - U) * Y1;
  X = X - (Z + U);
  R = Y * Y1;
  S = Z * Y2;
  T = T - Y;
  Y = (U - Y) + R;
  Z = S - (Z + U + U);
  R = (Y2 + U) * Y1;
  Y1 = Y2 * Y1;
  R = R - Y2;
  Y1 = Y1 - 0.5L;

  if (Z != 6) {
    abort();
  }

  exit(0);
}
