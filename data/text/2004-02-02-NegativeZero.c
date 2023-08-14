// Modification timestamp: 2023-08-14 17:16:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2004-02-02-NegativeZero.c
extern int printf(const char *str, ...);
void test(double X) {
  printf("%f %f\n", -0.0 - X, -X);
}
int main() {
  test(+0.0);
  test(-0.0);
  printf("negzero = %f  poszero = %f\n", -0.0, +0.0);
  return 0;
}
