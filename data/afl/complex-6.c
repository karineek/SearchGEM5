// Modification timestamp: 2023-08-14 14:18:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/complex-6.c

#include <stdlib.h>
#include <stdio.h>

int err;

#define TEST(TYPE, FUNC)                    \
__complex__ TYPE                        \
ctest_ ## FUNC (__complex__ TYPE x)               \
{                               \
  __complex__ TYPE res;                        \
                                \
  res = ~x;                           \
                                \
  return res;                           \
}                               \
                                \
void                                \
test_ ## FUNC (void)                        \
{                               \
  __complex__ TYPE res, x;                    \
                                \
  x = (__complex__ TYPE)atoi(argv[1]) + (__complex__ TYPE)atoi(argv[2]) * I;                  \
                                \
  res = ctest_ ## FUNC (x);                   \
                                \
  if (res != (~x))                 \
    {                               \
      printf ("test_" #FUNC " failed\n");           \
      ++err;                          \
    }                               \
}


TEST(float, float)
TEST(double, double)
TEST(long double, long_double)
TEST(int, int)
TEST(long int, long_int)

int
main (int argc, char *argv[])
{

  if (argc != 3) {
    printf("Usage: %s <real> <imaginary>\n", argv[0]);
    return 1;
  }

  err = 0;

  test_float ();
  test_double ();
  test_long_double ();
  test_int ();
  test_long_int ();

  if (err != 0)
    abort ();

  return 0;
}

