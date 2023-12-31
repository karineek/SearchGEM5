// Modification timestamp: 2023-08-14 17:15:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2003-07-09-SignedArgs.c

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

typedef signed char schar;

short getShort(schar c, schar c2, schar c3, short s, short s2, int i);
int getUnknown(schar c, ...);

int passShort(schar c, short s)
{
  schar c2 = s + c;
  schar c3 = s - c;
  short s2 = s * c;
  int i = s * s * c * c;
  short s3 = getShort(c, c2, c3, s, s2, i);
  return getUnknown(c, c2, c3, s, s2, s3, i);
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <c> <s>\n", argv[0]);
    return 1;
  }

  schar c = (schar)atoi(argv[1]);
  short s = (short)atoi(argv[2]);
  printf("%d\n", passShort(c, s));
  return 0;
}

short getShort(schar c, schar c2, schar c3, short s, short s2, int i)
{
  int bc = c == (schar)-128;
  int bc2 = c2 == (schar)116;
  int bc3 = c3 == (schar)116;
  int bs = s == (short)-3852;
  int bs2 = s2 == (short)-31232;
  int bi = i == (int)-1708916736;

  printf("getShort():\t%d %d %d %d %d %d\n", bc, bc2, bc3, bs, bs2, bi);
  printf("getShort():\t%d %d %d %d %d %d\n", c, c2, c3, s, s2, i);
  return (c + c2 + c3 + s + s2) + (short)i;
}

int getUnknown(schar c, ...)
{
  schar c2, c3;
  short s, s2, s3;
  int i;
  va_list ap;

  va_start(ap, c);
  c2 = (schar)va_arg(ap, int);
  c3 = (schar)va_arg(ap, int);
  s = (short)va_arg(ap, int);
  s2 = (short)va_arg(ap, int);
  s3 = (short)va_arg(ap, int);
  i = va_arg(ap, int);
  va_end(ap);

  printf("getUnknown():\t%d %d %d %d %d %d %d\n", c, c2, c3, s, s2, s3, i);
  return c + c2 + c3 + s + s2 + s3 + i;
}
