// Modification timestamp: 2023-08-14 15:06:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr40386.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

#define CHAR_BIT 8

#define ROR(a,b) (((a) >> (b)) | ((a) << ((sizeof (a) * CHAR_BIT) - (b))))
#define ROL(a,b) (((a) << (b)) | ((a) >> ((sizeof (a) * CHAR_BIT) - (b))))

int main(int argc, char *argv[]) {
  char c = (char)0xf234;
  short s = (short)0xf234;
  int i = (int)0xf234;
  long l = (long)0xf2345678L;
  long long ll = (long long)0xf2345678abcdef0LL;
  int shift1 = 4;
  int shift2 = (sizeof(long long) * CHAR_BIT) - shift1;

  if (ROR(c, shift1) != ROR((char)0xf234, 4))
    abort();

  if (ROR(c, 4) != ROR((char)0xf234, 4))
    abort();

  if (ROR(s, shift1) != ROR((short)0xf234, 4))
    abort();

  if (ROR(s, 4) != ROR((short)0xf234, 4))
    abort();

  if (ROR(i, shift1) != ROR((int)0xf234, 4))
    abort();

  if (ROR(i, 4) != ROR((int)0xf234, 4))
    abort();

  if (ROR(l, shift1) != ROR((long)0xf2345678L, 4))
    abort();

  if (ROR(l, 4) != ROR((long)0xf2345678L, 4))
    abort();

  if (ROR(ll, shift1) != ROR((long long)0xf2345678abcdef0LL, 4))
    abort();

  if (ROR(ll, 4) != ROR((long long)0xf2345678abcdef0LL, 4))
    abort();

  if (ROR(ll, shift2) != ROR((long long)0xf2345678abcdef0LL, (sizeof(long long) * CHAR_BIT) - 4))
    abort();

  if (ROR(ll, (sizeof(long long) * CHAR_BIT) - 4) != ROR((long long)0xf2345678abcdef0LL, (sizeof(long long) * CHAR_BIT) - 4))
    abort();

  if (ROL(c, shift1) != ROL((char)0xf234, 4))
    abort();

  if (ROL(c, 4) != ROL((char)0xf234, 4))
    abort();

  if (ROL(s, shift1) != ROL((short)0xf234, 4))
    abort();

  if (ROL(s, 4) != ROL((short)0xf234, 4))
    abort();

  if (ROL(i, shift1) != ROL((int)0xf234, 4))
    abort();

  if (ROL(i, 4) != ROL((int)0xf234, 4))
    abort();

  if (ROL(l, shift1) != ROL((long)0xf2345678L, 4))
    abort();

  if (ROL(l, 4) != ROL((long)0xf2345678L, 4))
    abort();

  if (ROL(ll, shift1) != ROL((long long)0xf2345678abcdef0LL, 4))
    abort();

  if (ROL(ll, 4) != ROL((long long)0xf2345678abcdef0LL, 4))
    abort();

  if (ROL(ll, shift2) != ROL((long long)0xf2345678abcdef0LL, (sizeof(long long) * CHAR_BIT) - 4))
    abort();

  if (ROL(ll, (sizeof(long long) * CHAR_BIT) - 4) != ROL((long long)0xf2345678abcdef0LL, (sizeof(long long) * CHAR_BIT) - 4))
    abort();

  exit(0);
}
