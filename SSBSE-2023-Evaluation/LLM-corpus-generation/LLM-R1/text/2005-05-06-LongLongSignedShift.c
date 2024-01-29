// Modification timestamp: 2023-08-14 17:32:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/Regression/C//2005-05-06-LongLongSignedShift.c
extern int printf(const char *str, ...);

int main(int argc, char **argv) {
  printf("%lld\n", (argc-100LL) >> 38);

  return 0;
}
