
// Modification timestamp: 2023-08-10 15:41:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/OpenMP/conditional-gnu-ext.c

extern void abort();

_Complex int getComplex(_Complex int val) {
  static int count;
  if (count++)
    abort();
  return val;
}

_Complex int doo() {
    _Complex int cond;
    _Complex int rhs;

    return getComplex(1+2i) ? : rhs;
}

int main() {
  doo();
  return 0;
}

