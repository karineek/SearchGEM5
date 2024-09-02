// Modification timestamp: 2023-08-14 15:05:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr39501.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

#define min1(a,b) ((a) < (b) ? (a) : (b))
#define max1(a,b) ((a) > (b) ? (a) : (b))

#define min2(a,b) ((a) <= (b) ? (a) : (b))
#define max2(a,b) ((a) >= (b) ? (a) : (b))

#define F(type,n)						\
  type __attribute__((noinline)) type##_##n(type a, type b)	\
  {								\
    return n(a, b);						\
  }

F(float,min1)
F(float,min2)
F(float,max1)
F(float,max2)

F(double,min1)
F(double,min2)
F(double,max1)
F(double,max2)

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (float_min1(atof(argv[1]), atof(argv[2])) != atof(argv[3])) abort();
  if (float_min1(atof(argv[2]), atof(argv[1])) != atof(argv[3])) abort();
  if (float_min1(atof(argv[1]), atof(argv[3])) != atof(argv[4])) abort();
  if (float_min1(atof(argv[3]), atof(argv[1])) != atof(argv[4])) abort();
  if (float_min1(atof(argv[2]), atof(argv[3])) != atof(argv[5])) abort();
  if (float_min1(atof(argv[3]), atof(argv[2])) != atof(argv[5])) abort();

  if (float_max1(atof(argv[1]), atof(argv[2])) != atof(argv[6])) abort();
  if (float_max1(atof(argv[2]), atof(argv[1])) != atof(argv[6])) abort();
  if (float_max1(atof(argv[1]), atof(argv[3])) != atof(argv[7])) abort();
  if (float_max1(atof(argv[3]), atof(argv[1])) != atof(argv[7])) abort();
  if (float_max1(atof(argv[2]), atof(argv[3])) != atof(argv[8])) abort();
  if (float_max1(atof(argv[3]), atof(argv[2])) != atof(argv[8])) abort();

  if (float_min2(atof(argv[1]), atof(argv[2])) != atof(argv[3])) abort();
  if (float_min2(atof(argv[2]), atof(argv[1])) != atof(argv[3])) abort();
  if (float_min2(atof(argv[1]), atof(argv[3])) != atof(argv[4])) abort();
  if (float_min2(atof(argv[3]), atof(argv[1])) != atof(argv[4])) abort();
  if (float_min2(atof(argv[2]), atof(argv[3])) != atof(argv[5])) abort();
  if (float_min2(atof(argv[3]), atof(argv[2])) != atof(argv[5])) abort();

  if (float_max2(atof(argv[1]), atof(argv[2])) != atof(argv[6])) abort();
  if (float_max2(atof(argv[2]), atof(argv[1])) != atof(argv[6])) abort();
  if (float_max2(atof(argv[1]), atof(argv[3])) != atof(argv[7])) abort();
  if (float_max2(atof(argv[3]), atof(argv[1])) != atof(argv[7])) abort();
  if (float_max2(atof(argv[2]), atof(argv[3])) != atof(argv[8])) abort();
  if (float_max2(atof(argv[3]), atof(argv[2])) != atof(argv[8])) abort();

  if (double_min1(atof(argv[1]), atof(argv[2])) != atof(argv[3])) abort();
  if (double_min1(atof(argv[2]), atof(argv[1])) != atof(argv[3])) abort();
  if (double_min1(atof(argv[1]), atof(argv[3])) != atof(argv[4])) abort();
  if (double_min1(atof(argv[3]), atof(argv[1])) != atof(argv[4])) abort();
  if (double_min1(atof(argv[2]), atof(argv[3])) != atof(argv[5])) abort();
  if (double_min1(atof(argv[3]), atof(argv[2])) != atof(argv[5])) abort();

  if (double_max1(atof(argv[1]), atof(argv[2])) != atof(argv[6])) abort();
  if (double_max1(atof(argv[2]), atof(argv[1])) != atof(argv[6])) abort();
  if (double_max1(atof(argv[1]), atof(argv[3])) != atof(argv[7])) abort();
  if (double_max1(atof(argv[3]), atof(argv[1])) != atof(argv[7])) abort();
  if (double_max1(atof(argv[2]), atof(argv[3])) != atof(argv[8])) abort();
  if (double_max1(atof(argv[3]), atof(argv[2])) != atof(argv[8])) abort();

  if (double_min2(atof(argv[1]), atof(argv[2])) != atof(argv[3])) abort();
  if (double_min2(atof(argv[2]), atof(argv[1])) != atof(argv[3])) abort();
  if (double_min2(atof(argv[1]), atof(argv[3])) != atof(argv[4])) abort();
  if (double_min2(atof(argv[3]), atof(argv[1])) != atof(argv[4])) abort();
  if (double_min2(atof(argv[2]), atof(argv[3])) != atof(argv[5])) abort();
  if (double_min2(atof(argv[3]), atof(argv[2])) != atof(argv[5])) abort();

  if (double_max2(atof(argv[1]), atof(argv[2])) != atof(argv[6])) abort();
  if (double_max2(atof(argv[2]), atof(argv[1])) != atof(argv[6])) abort();
  if (double_max2(atof(argv[1]), atof(argv[3])) != atof(argv[7])) abort();
  if (double_max2(atof(argv[3]), atof(argv[1])) != atof(argv[7])) abort();
  if (double_max2(atof(argv[2]), atof(argv[3])) != atof(argv[8])) abort();
  if (double_max2(atof(argv[3]), atof(argv[2])) != atof(argv[8])) abort();

  exit(0);
}
