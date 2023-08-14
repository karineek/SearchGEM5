// Modification timestamp: 2023-08-14 13:01:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050121-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort ();

#define T(type, name) \
__attribute__((pure)) _Complex type		\
foo_##name (int x)				\
{						\
  _Complex type r;				\
  __real r = x + 1;				\
  __imag r = x - 1;				\
  return r;					\
}						\
						\
void						\
bar_##name (type *x)				\
{						\
  *x = __real foo_##name (5);			\
}						\
						\
void						\
baz_##name (type *x)				\
{						\
  *x = __imag foo_##name (5);			\
}

typedef long double ldouble_t;
typedef long long llong;

T (float, float)
T (double, double)
T (long double, ldouble_t)
T (char, char)
T (short, short)
T (int, int)
T (long, long)
T (long long, llong)
#undef T

int
main (int argc, char *argv[])
{
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

#define T(type, name) \
  {						\
    type var = 0;				\
    bar_##name (&var);				\
    if (var != 6)				\
      abort ();					\
    var = 0;					\
    baz_##name (&var);				\
    if (var != 4)				\
      abort ();					\
  }
  T (float, float)
  T (double, double)
  T (long double, ldouble_t)
  T (char, char)
  T (short, short)
  T (int, int)
  T (long, long)
  T (long long, llong)
  return 0;
}
