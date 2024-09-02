// Modification timestamp: 2023-08-14 17:11:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-05-02-CastTest3.c
int printf(const char *, ...);

int main(int argc, char** argv) {
  short s1 = (argc >= 3)? argc : -769; /* 0xf7ff = -769 */

  unsigned short us2 = (unsigned short) s1;     /* 0xf7ff = 64767 */

  printf("s1   = %d\n",   s1);
  printf("us2  = %u\n",   us2);
  return 0;
}
