
// Modification timestamp: 2023-08-10 16:08:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/pointer_arithmetic.c

#include <stdlib.h>

typedef struct {
  int w;
//  float x;
//  double y;
//  long long z;
} S1Ty;

typedef struct {
  S1Ty A, B;
} S2Ty;

void takeS1(S1Ty *V) {}
void takeVoid(void *P) {}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  S2Ty E;
  takeS1(&E.B);
  takeVoid(&E);
  return 0;
}
