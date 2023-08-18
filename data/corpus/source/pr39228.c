// Modification timestamp: 2023-08-14 15:03:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr39228.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

extern void abort(void);

static inline int __attribute__((always_inline)) testf(float b)
{
  float c = 1.01f * b;

  return isinf(c);
}

static inline int __attribute__((always_inline)) test(double b)
{
  double c = 1.01 * b;

  return isinf(c);
}

static inline int __attribute__((always_inline)) testl(long double b)
{
  long double c = 1.01L * b;

  return isinf(c);
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  float __FLT_MAX__ = atof(argv[1]);
  double __DBL_MAX__ = atof(argv[2]);
  long double __LDBL_MAX__ = atof(argv[3]);

  if (testf(__FLT_MAX__) < 1)
    abort();

  if (test(__DBL_MAX__) < 1)
    abort();

  if (testl(__LDBL_MAX__) < 1)
    abort();

  return 0;
}


//Note: Replace `<value>` in the usage message with appropriate input values.