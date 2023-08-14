
// Modification timestamp: 2023-08-10 14:46:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/MallocBench/espresso/irred.c

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/* 5 bytes. */
typedef struct DWordS_struct    { int i; char c; } DWordS;

/* 12 bytes if d is 4-byte aligned; 16 bytes if d is 8-byte aligned. */
typedef struct QuadWordS_struct { int i; double d; } QuadWordS;

/* 20 bytes if d is 4-byte aligned; 28 bytes if d is 8-byte aligned
 * (assuming pointer size is 4 bytes and 8 bytes respectively). */
typedef struct LargeS_struct { int i; double d; DWordS* ptr; int j; } LargeS;

void test(char *fmt, ...) {
  va_list ap, aq;
  int d;
  char c, *s;
  DWordS dw;
  QuadWordS qw;
  LargeS ls;

  va_start(ap, fmt);

  va_copy(aq, ap);    /* test va_copy */
  va