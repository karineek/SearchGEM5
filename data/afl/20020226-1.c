// Modification timestamp: 2023-08-14 12:11:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020226-1.c

#include <stdio.h>
#include <stdlib.h>

#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

#define ROR(a,b) (((a) >> (b)) | ((a) << ((sizeof (a) * CHAR_BIT) - (b))))
#define ROL(a,b) (((a) << (b)) | ((a) >> ((sizeof (a) * CHAR_BIT) - (b))))

#define SHIFT1 argv[1][0]
#define SHIFT2 ((sizeof (long long) * CHAR_BIT) - SHIFT1)

unsigned char uc = argc > 1 ? atoi(argv[2]) : 0x1234U;
unsigned short us = argc > 1 ? atoi(argv[3]) : 0x1234U;
unsigned int ui = argc > 1 ? atoi(argv[4]) : 0x1234U;
unsigned long ul = argc > 1 ? atoi(argv[5]) : 0x12345678LU;
unsigned long long ull = argc > 1 ? atoll(argv[6]) : 0x12345678abcdef0LLU;

int main(int argc, char *argv[]) {
  if (ROR(uc, SHIFT1) != ROR(CHAR_VALUE, SHIFT1))
    abort();

  if (ROR(uc, SHIFT1) != ROR(CHAR_VALUE, SHIFT1))
    abort();

  if (ROR(us, SHIFT1) != ROR(SHORT_VALUE, SHIFT1))
    abort();

  if (ROR(us, SHIFT1) != ROR(SHORT_VALUE, SHIFT1))
    abort();

  if (ROR(ui, SHIFT1) != ROR(INT_VALUE, SHIFT1))
    abort();

  if (ROR(ui, SHIFT1) != ROR(INT_VALUE, SHIFT1))
    abort();

  if (ROR(ul, SHIFT1) != ROR(LONG_VALUE, SHIFT1))
    abort();

  if (ROR(ul, SHIFT1) != ROR(LONG_VALUE, SHIFT1))
    abort();

  if (ROR(ull, SHIFT1) != ROR(LL_VALUE, SHIFT1))
    abort();

  if (ROR(ull, SHIFT1) != ROR(LL_VALUE, SHIFT1))
    abort();

  if (ROR(ull, SHIFT2) != ROR(LL_VALUE, SHIFT2))
    abort();

  if (ROR(ull, SHIFT2) != ROR(LL_VALUE, SHIFT2))
    abort();

  if (ROL(uc, SHIFT1) != ROL(CHAR_VALUE, SHIFT1))
    abort();

  if (ROL(uc, SHIFT1) != ROL(CHAR_VALUE, SHIFT1))
    abort();

  if (ROL(us, SHIFT1) != ROL(SHORT_VALUE, SHIFT1))
    abort();

  if (ROL(us, SHIFT1) != ROL(SHORT_VALUE, SHIFT1))
    abort();

  if (ROL(ui, SHIFT1) != ROL(INT_VALUE, SHIFT1))
    abort();

  if (ROL(ui, SHIFT1) != ROL(INT_VALUE, SHIFT1))
    abort();

  if (ROL(ul, SHIFT1) != ROL(LONG_VALUE, SHIFT1))
    abort();

  if (ROL(ul, SHIFT1) != ROL(LONG_VALUE, SHIFT1))
    abort();

  if (ROL(ull, SHIFT1) != ROL(LL_VALUE, SHIFT1))
    abort();

  if (ROL(ull, SHIFT1) != ROL(LL_VALUE, SHIFT1))
    abort();

  if (ROL(ull, SHIFT2) != ROL(LL_VALUE, SHIFT2))
    abort();

  if (ROL(ull, SHIFT2) != ROL(LL_VALUE, SHIFT2))
    abort();

  exit(0);
}

Note: Please make sure to add error checking for invalid input in the main function.