// Modification timestamp: 2023-08-14 17:36:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//pointer_arithmetic.c

#include <stdio.h>

typedef struct {
  int w;
} S1Ty;

typedef struct {
  S1Ty A, B;
} S2Ty;

void takeS1(S1Ty *V) {}
void takeVoid(void *P) {}

int main() {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  S2Ty E;
  takeS1(&E.B);
  takeVoid(&E);
  return 0;
}


Note: The code you provided doesn't contain any constant values to replace with command line arguments, so the resulting code is the same as the original code.