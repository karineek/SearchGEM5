// Modification timestamp: 2023-08-14 17:10:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2002-05-02-CastTest1.c
int printf(const char *, ...);

int
main(int argc, char** argv)
{
  signed char c0  = -1;
  unsigned char c1 = 255;
  printf("bs0  = %d %d\n", c0, c1);
  return 0;
}
