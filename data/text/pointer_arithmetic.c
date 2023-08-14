// Modification timestamp: 2023-08-14 17:36:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//pointer_arithmetic.c
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

int main() {
  S2Ty E;
  takeS1(&E.B);
  takeVoid(&E);
  return 0;
}

