// Modification timestamp: 2023-08-14 12:17:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020506-1.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

extern void abort(void);

void test1(signed char c, int set);
void test2(unsigned char c, int set);
void test3(short s, int set);
void test4(unsigned short s, int set);
void test5(int i, int set);
void test6(unsigned int i, int set);
void test7(long long l, int set);
void test8(unsigned long long l, int set);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  signed char c = atoi(argv[1]);
  unsigned char uc = atoi(argv[2]);
  short s = atoi(argv[3]);
  unsigned short us = atoi(argv[4]);
  int i = atoi(argv[5]);
  unsigned int ui = atoi(argv[6]);
  long long ll = atol(argv[7]);
  unsigned long long ull = atol(argv[8]);

  test1(c, 0);
  test1(SCHAR_MAX, 0);
  test1(SCHAR_MIN, 1);
  test1(UCHAR_MAX, 1);

  test2(uc, 0);
  test2(SCHAR_MAX, 0);
  test2(SCHAR_MIN, 1);
  test2(UCHAR_MAX, 1);

  test3(s, 0);
  test3(SHRT_MAX, 0);
  test3(SHRT_MIN, 1);
  test3(USHRT_MAX, 1);

  test4(us, 0);
  test4(SHRT_MAX, 0);
  test4(SHRT_MIN, 1);
  test4(USHRT_MAX, 1);

  test5(i, 0);
  test5(INT_MAX, 0);
  test5(INT_MIN, 1);
  test5(UINT_MAX, 1);

  test6(ui, 0);
  test6(INT_MAX, 0);
  test6(INT_MIN, 1);
  test6(UINT_MAX, 1);

  test7(ll, 0);
  test7(LONG_LONG_MAX, 0);
  test7(LONG_LONG_MIN, 1);
  test7(ULONG_LONG_MAX, 1);

  test8(ull, 0);
  test8(LONG_LONG_MAX, 0);
  test8(LONG_LONG_MIN, 1);
  test8(ULONG_LONG_MAX, 1);

  return 0;
}

void test1(signed char c, int set) {
  if ((c & (SCHAR_MAX + 1)) == 0) {
    if (set)
      abort();
  } else if (!set)
    abort();

  if ((c & (SCHAR_MAX + 1)) != 0) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((c & (SCHAR_MAX + 1)) == (SCHAR_MAX + 1)) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((c & (SCHAR_MAX + 1)) != (SCHAR_MAX + 1)) {
    if (set)
      abort();
  } else if (!set)
    abort();
}

void test2(unsigned char c, int set) {
  if ((c & (SCHAR_MAX + 1)) == 0) {
    if (set)
      abort();
  } else if (!set)
    abort();

  if ((c & (SCHAR_MAX + 1)) != 0) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((c & (SCHAR_MAX + 1)) == (SCHAR_MAX + 1)) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((c & (SCHAR_MAX + 1)) != (SCHAR_MAX + 1)) {
    if (set)
      abort();
  } else if (!set)
    abort();
}

void test3(short s, int set) {
  if ((s & (SHRT_MAX + 1)) == 0) {
    if (set)
      abort();
  } else if (!set)
    abort();

  if ((s & (SHRT_MAX + 1)) != 0) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((s & (SHRT_MAX + 1)) == (SHRT_MAX + 1)) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((s & (SHRT_MAX + 1)) != (SHRT_MAX + 1)) {
    if (set)
      abort();
  } else if (!set)
    abort();
}

void test4(unsigned short s, int set) {
  if ((s & (SHRT_MAX + 1)) == 0) {
    if (set)
      abort();
  } else if (!set)
    abort();

  if ((s & (SHRT_MAX + 1)) != 0) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((s & (SHRT_MAX + 1)) == (SHRT_MAX + 1)) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((s & (SHRT_MAX + 1)) != (SHRT_MAX + 1)) {
    if (set)
      abort();
  } else if (!set)
    abort();
}

void test5(int i, int set) {
  if ((i & (INT_MAX + 1U)) == 0) {
    if (set)
      abort();
  } else if (!set)
    abort();

  if ((i & (INT_MAX + 1U)) != 0) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((i & (INT_MAX + 1U)) == (INT_MAX + 1U)) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((i & (INT_MAX + 1U)) != (INT_MAX + 1U)) {
    if (set)
      abort();
  } else if (!set)
    abort();
}

void test6(unsigned int i, int set) {
  if ((i & (INT_MAX + 1U)) == 0) {
    if (set)
      abort();
  } else if (!set)
    abort();

  if ((i & (INT_MAX + 1U)) != 0) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((i & (INT_MAX + 1U)) == (INT_MAX + 1U)) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((i & (INT_MAX + 1U)) != (INT_MAX + 1U)) {
    if (set)
      abort();
  } else if (!set)
    abort();
}

void test7(long long l, int set) {
  if ((l & (LONG_LONG_MAX + 1ULL)) == 0) {
    if (set)
      abort();
  } else if (!set)
    abort();

  if ((l & (LONG_LONG_MAX + 1ULL)) != 0) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((l & (LONG_LONG_MAX + 1ULL)) == (LONG_LONG_MAX + 1ULL)) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((l & (LONG_LONG_MAX + 1ULL)) != (LONG_LONG_MAX + 1ULL)) {
    if (set)
      abort();
  } else if (!set)
    abort();
}

void test8(unsigned long long l, int set) {
  if ((l & (LONG_LONG_MAX + 1ULL)) == 0) {
    if (set)
      abort();
  } else if (!set)
    abort();

  if ((l & (LONG_LONG_MAX + 1ULL)) != 0) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((l & (LONG_LONG_MAX + 1ULL)) == (LONG_LONG_MAX + 1ULL)) {
    if (!set)
      abort();
  } else if (set)
    abort();

  if ((l & (LONG_LONG_MAX + 1ULL)) != (LONG_LONG_MAX + 1ULL)) {
    if (set)
      abort();
  } else if (!set)
    abort();
}

