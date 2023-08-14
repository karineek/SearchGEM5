// Modification timestamp: 2023-08-14 12:18:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020508-3.c

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

#define ROR(a,b) (((a) >> (b)) | ((a) << ((sizeof (a) * CHAR_BIT) - (b))))
#define ROL(a,b) (((a) << (b)) | ((a) >> ((sizeof (a) * CHAR_BIT) - (b))))

#define SHIFT1 argv[1][0]
#define SHIFT2 ((sizeof (long long) * CHAR_BIT) - atoi(argv[2]))

#define CHAR_VALUE ((char)0xf234)
#define SHORT_VALUE ((short)0xf234)
#define INT_VALUE ((int)0xf234)
#define LONG_VALUE ((long)0xf2345678L)
#define LL_VALUE ((long long)0xf2345678abcdef0LL)

int main(int argc, char *argv[]) {
  if (ROR (CHAR_VALUE, atoi(argv[1])) != ROR (CHAR_VALUE, SHIFT1))
    abort ();

  if (ROR (CHAR_VALUE, SHIFT1) != ROR (CHAR_VALUE, SHIFT1))
    abort ();

  if (ROR (SHORT_VALUE, atoi(argv[1])) != ROR (SHORT_VALUE, SHIFT1))
    abort ();

  if (ROR (SHORT_VALUE, SHIFT1) != ROR (SHORT_VALUE, SHIFT1))
    abort ();

  if (ROR (INT_VALUE, atoi(argv[1])) != ROR (INT_VALUE, SHIFT1))
    abort ();

  if (ROR (INT_VALUE, SHIFT1) != ROR (INT_VALUE, SHIFT1))
    abort ();

  if (ROR (LONG_VALUE, atoi(argv[1])) != ROR (LONG_VALUE, SHIFT1))
    abort ();

  if (ROR (LONG_VALUE, SHIFT1) != ROR (LONG_VALUE, SHIFT1))
    abort ();

  if (ROR (LL_VALUE, atoi(argv[1])) != ROR (LL_VALUE, SHIFT1))
    abort ();

  if (ROR (LL_VALUE, SHIFT1) != ROR (LL_VALUE, SHIFT1))
    abort ();

  if (ROR (LL_VALUE, atoi(argv[2])) != ROR (LL_VALUE, SHIFT2))
    abort ();

  if (ROR (LL_VALUE, SHIFT2) != ROR (LL_VALUE, SHIFT2))
    abort ();

  if (ROL (CHAR_VALUE, atoi(argv[1])) != ROL (CHAR_VALUE, SHIFT1))
    abort ();

  if (ROL (CHAR_VALUE, SHIFT1) != ROL (CHAR_VALUE, SHIFT1))
    abort ();

  if (ROL (SHORT_VALUE, atoi(argv[1])) != ROL (SHORT_VALUE, SHIFT1))
    abort ();

  if (ROL (SHORT_VALUE, SHIFT1) != ROL (SHORT_VALUE, SHIFT1))
    abort ();

  if (ROL (INT_VALUE, atoi(argv[1])) != ROL (INT_VALUE, SHIFT1))
    abort ();

  if (ROL (INT_VALUE, SHIFT1) != ROL (INT_VALUE, SHIFT1))
    abort ();

  if (ROL (LONG_VALUE, atoi(argv[1])) != ROL (LONG_VALUE, SHIFT1))
    abort ();

  if (ROL (LONG_VALUE, SHIFT1) != ROL (LONG_VALUE, SHIFT1))
    abort ();

  if (ROL (LL_VALUE, atoi(argv[1])) != ROL (LL_VALUE, SHIFT1))
    abort ();

  if (ROL (LL_VALUE, SHIFT1) != ROL (LL_VALUE, SHIFT1))
    abort ();

  if (ROL (LL_VALUE, atoi(argv[2])) != ROL (LL_VALUE, SHIFT2))
    abort ();

  if (ROL (LL_VALUE, SHIFT2) != ROL (LL_VALUE, SHIFT2))
    abort ();

  exit (0);
}
