
// Modification timestamp: 2023-08-10 15:09:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/ASC_Sequoia/C/Test2001/2004-02-02-NegativeZero.c

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
