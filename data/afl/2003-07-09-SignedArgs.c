
// Modification timestamp: 2023-08-10 14:58:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/SingleSource/UnitTests/2003-07-09-SignedArgs.c

#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

typedef signed char schar;

short getShort(schar c, schar c2, schar c3, short s, short s2, int i);
int   getUnknown(schar c, ...);

int passShort(schar c, short s)
{
  schar c2 = s + c;
  schar c3 = s - c;
  short s2 = s * c;
  int    i = s * s * c * c;
  short s3 = getShort(c, c2, c3, s, s2, i);   /* args shd be sign-extended */
  return getUnknown(c, c2, c3, s, s2, s3, i); /* args shd be promoted to int */
}

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  schar c = (schar)atoi(argv[1]);
  short s = (short)atoi(argv[2]);

  printf("%d\n", passShort(c, s));
  return 0;
}

short getShort(schar c, schar c2, schar c3, short s, short s2, int i)
{
  int bc  = c  == (schar) -128;
