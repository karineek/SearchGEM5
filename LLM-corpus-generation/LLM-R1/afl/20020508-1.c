// Modification timestamp: 2023-08-14 12:17:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020508-1.c

#include <stdio.h>
#include <stdlib.h>

#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

#define ROR(a,b) (((a) >> (b)) | ((a) << ((sizeof (a) * CHAR_BIT) - (b))))
#define ROL(a,b) (((a) << (b)) | ((a) >> ((sizeof (a) * CHAR_BIT) - (b))))

#define SHIFT1 (atoi(argv[1]))
#define SHIFT2 ((sizeof (long long) * CHAR_BIT) - SHIFT1)

unsigned char uc = CHAR_VALUE;
unsigned short us = SHORT_VALUE;
unsigned int ui = INT_VALUE;
unsigned long ul = LONG_VALUE;
unsigned long long ull = LL_VALUE;
int shift1 = SHIFT1;
int shift2 = SHIFT2;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (ROR (uc, shift1) != ROR (CHAR_VALUE, SHIFT1))
    abort ();

  if (ROR (uc, SHIFT1) != ROR (CHAR_VALUE, SHIFT1))
    abort ();

  if (ROR (us, shift1) != ROR (SHORT_VALUE, SHIFT1))
    abort ();

  if (ROR (us, SHIFT1) != ROR (SHORT_VALUE, SHIFT1))
    abort ();

  if (ROR (ui, shift1) != ROR (INT_VALUE, SHIFT1))
    abort ();

  if (ROR (ui, SHIFT1) != ROR (INT_VALUE, SHIFT1))
    abort ();

  if (ROR (ul, shift1) != ROR (LONG_VALUE, SHIFT1))
    abort ();

  if (ROR (ul, SHIFT1) != ROR (LONG_VALUE, SHIFT1))
    abort ();

  if (ROR (ull, shift1) != ROR (LL_VALUE, SHIFT1))
    abort ();

  if (ROR (ull, SHIFT1) != ROR (LL_VALUE, SHIFT1))
    abort ();

  if (ROR (ull, shift2) != ROR (LL_VALUE, SHIFT2))
    abort ();

  if (ROR (ull, SHIFT2) != ROR (LL_VALUE, SHIFT2))
    abort ();

  if (ROL (uc, shift1) != ROL (CHAR_VALUE, SHIFT1))
    abort ();

  if (ROL (uc, SHIFT1) != ROL (CHAR_VALUE, SHIFT1))
    abort ();

  if (ROL (us, shift1) != ROL (SHORT_VALUE, SHIFT1))
    abort ();

  if (ROL (us, SHIFT1) != ROL (SHORT_VALUE, SHIFT1))
    abort ();

  if (ROL (ui, shift1) != ROL (INT_VALUE, SHIFT1))
    abort ();

  if (ROL (ui, SHIFT1) != ROL (INT_VALUE, SHIFT1))
    abort ();

  if (ROL (ul, shift1) != ROL (LONG_VALUE, SHIFT1))
    abort ();

  if (ROL (ul, SHIFT1) != ROL (LONG_VALUE, SHIFT1))
    abort ();

  if (ROL (ull, shift1) != ROL (LL_VALUE, SHIFT1))
    abort ();

  if (ROL (ull, SHIFT1) != ROL (LL_VALUE, SHIFT1))
    abort ();

  if (ROL (ull, shift2) != ROL (LL_VALUE, SHIFT2))
    abort ();

  if (ROL (ull, SHIFT2) != ROL (LL_VALUE, SHIFT2))
    abort ();

  return 0;
}

Note: Don't forget to replace `CHAR_VALUE`, `SHORT_VALUE`, `INT_VALUE`, `LONG_VALUE`, and `LL_VALUE` with their respective values.