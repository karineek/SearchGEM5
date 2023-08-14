c
// Modification timestamp: 2023-08-10 15:39:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/C/StructModifyTest.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int w;
  float x;
  double y;
  long long z;
} S1Ty;

typedef struct {
  S1Ty A, B;
} S2Ty;

extern int printf(const char *str, ...);
void printS1(S1Ty *V) {
  printf("%d, %f, %f, %lld\n", V->w, V->x, V->y, V->z);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  S2Ty E;
  E.A.w = atoi(argv[1]); // args assignment
  E.A.x = 123.42f;
  E.A.y = 19.0;
  E.A.z = 123455678902ll;
  E.B.w = 2;
  E.B.x = 23.42f;
  E.B.y = 29.0;
  E.B.z = 23455678902ll;

  printS1(&E.A);
  printS1(&E.B);
  return 0;
}
