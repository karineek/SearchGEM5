// Modification timestamp: 2023-08-14 12:19:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020510-1.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern void abort(void);

void testc(char c, int ok) {
  if ((c>=1) && (c<=SCHAR_MAX)) {
    if (!ok) abort();
  }
  else
    if (ok) abort();
}

void tests(short s, int ok) {
  if ((s>=1) && (s<=SHRT_MAX)) {
    if (!ok) abort();
  }
  else
    if (ok) abort();
}

void testi(int i, int ok) {
  if ((i>=1) && (i<=INT_MAX)) {
    if (!ok) abort();
  }
  else
    if (ok) abort();
}

void testl(long l, int ok) {
  if ((l>=1) && (l<=LONG_MAX)) {
    if (!ok) abort();
  }
  else
    if (ok) abort();
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  testc(0, 0);
  testc(1, 1);
  testc(SCHAR_MAX, 1);
  testc(SCHAR_MAX + 1, 0);
  testc(UCHAR_MAX, 0);

  tests(0, 0);
  tests(1, 1);
  tests(SHRT_MAX, 1);
  tests(SHRT_MAX + 1, 0);
  tests(USHRT_MAX, 0);

  testi(0, 0);
  testi(1, 1);
  testi(INT_MAX, 1);
  testi(INT_MAX + 1U, 0);
  testi(UINT_MAX, 0);

  testl(0, 0);
  testl(1, 1);
  testl(LONG_MAX, 1);
  testl(LONG_MAX + 1UL, 0);
  testl(ULONG_MAX, 0);

  return 0;
}
