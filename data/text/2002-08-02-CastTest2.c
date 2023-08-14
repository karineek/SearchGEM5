// Modification timestamp: 2023-08-14 17:11:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-08-02-CastTest2.c
int printf(const char *, ...);

void test(short s1) {
  unsigned short us2 = (unsigned short) s1;     /* 0xf7ff = 64767 */

  printf("s1   = %d\n",   s1);
  printf("us2  = %u\n",   us2);
}

int main() {
  test(-769);
  return 0;
}
