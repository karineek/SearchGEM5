
// Modification timestamp: 2023-08-10 15:55:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/llvm-test/2005-05-06-LongLongSignedShift.c

extern int printf(const char *str, ...);

int main(int argc, char **argv) {
  printf("%lld\n", (argc-100LL) >> 38);

  return 0;
}
