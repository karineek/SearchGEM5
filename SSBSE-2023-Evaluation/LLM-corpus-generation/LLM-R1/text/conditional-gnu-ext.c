// Modification timestamp: 2023-08-14 17:28:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/conditional-gnu-ext.c
// rdar://8453812
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

