// Modification timestamp: 2023-08-14 17:17:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2005-07-15-Bitfield-ABI.c
// PR594

struct X {
  int Q :6;
   int A : 4;
   int Z : 22;
};

void test(struct X *P, int A) {
   P->A = A;
}

extern int printf(const char *str, ...);

int main() {
  union {
    int Y;
    struct X Z;
  } U;
  U.Y = ~0;
  test(&U.Z, 0);
  printf("%x\n", U.Y);
  return 0;
}
