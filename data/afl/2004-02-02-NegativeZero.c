
// Modification timestamp: 2023-08-10 15:09:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/ASC_Sequoia/C/Test2001/2004-02-02-NegativeZero.c

extern int printf(const char *str, ...);
void test(double X) {
  printf("%f %f\n", -0.0 - X, -X);
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  double X = atof(argv[1]);
  test(X);
  printf("negzero = %f  poszero = %f\n", -0.0, +0.0);
  return 0;
}
