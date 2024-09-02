// Modification timestamp: 2023-08-14 12:18:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020508-2.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

#define ROR(a,b) (((a) >> (b)) | ((a) << ((sizeof (a) * CHAR_BIT) - (b))))
#define ROL(a,b) (((a) << (b)) | ((a) >> ((sizeof (a) * CHAR_BIT) - (b))))

#define SHIFT1 4
#define SHIFT2 ((sizeof (long long) * CHAR_BIT) - SHIFT1)

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char c = atoi(argv[1]);
  short s = atoi(argv[2]);
  int i = atoi(argv[3]);
  long l = strtol(argv[4], NULL, 0);
  long long ll = strtoll(argv[5], NULL, 0);
  int shift1 = atoi(argv[6]);
  int shift2 = atoi(argv[7]);

  if (ROR (c, shift1) != ROR (c, shift1))
    abort ();

  if (ROR (c, SHIFT1) != ROR (c, SHIFT1))
    abort ();

  if (ROR (s, shift1) != ROR (s, shift1))
    abort ();

  if (ROR (s, SHIFT1) != ROR (s, SHIFT1))
    abort ();

  if (ROR (i, shift1) != ROR (i, shift1))
    abort ();

  if (ROR (i, SHIFT1) != ROR (i, SHIFT1))
    abort ();

  if (ROR (l, shift1) != ROR (l, shift1))
    abort ();

  if (ROR (l, SHIFT1) != ROR (l, SHIFT1))
    abort ();

  if (ROR (ll, shift1) != ROR (ll, shift1))
    abort ();

  if (ROR (ll, SHIFT1) != ROR (ll, SHIFT1))
    abort ();

  if (ROR (ll, shift2) != ROR (ll, shift2))
    abort ();

  if (ROR (ll, SHIFT2) != ROR (ll, SHIFT2))
    abort ();

  if (ROL (c, shift1) != ROL (c, shift1))
    abort ();

  if (ROL (c, SHIFT1) != ROL (c, SHIFT1))
    abort ();

  if (ROL (s, shift1) != ROL (s, shift1))
    abort ();

  if (ROL (s, SHIFT1) != ROL (s, SHIFT1))
    abort ();

  if (ROL (i, shift1) != ROL (i, shift1))
    abort ();

  if (ROL (i, SHIFT1) != ROL (i, SHIFT1))
    abort ();

  if (ROL (l, shift1) != ROL (l, shift1))
    abort ();

  if (ROL (l, SHIFT1) != ROL (l, SHIFT1))
    abort ();

  if (ROL (ll, shift1) != ROL (ll, shift1))
    abort ();

  if (ROL (ll, SHIFT1) != ROL (ll, SHIFT1))
    abort ();

  if (ROL (ll, shift2) != ROL (ll, shift2))
    abort ();

  if (ROL (ll, SHIFT2) != ROL (ll, SHIFT2))
    abort ();

  exit(0);
}
