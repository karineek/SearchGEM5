// Modification timestamp: 2023-08-14 13:36:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930930-2.c

#include <stdio.h>
#include <stdlib.h>

int test_endianness(int argc, char *argv[]) {
  union doubleword {
    double d;
    unsigned long u[2];
  } dw;
  
  dw.d = atof(argv[1]);
  return dw.u[0] != 0 ? 1 : 0;
}

int test_endianness_vol(int argc, char *argv[]) {
  union doubleword {
    volatile double d;
    volatile long u[2];
  } dw;
  
  dw.d = atof(argv[1]);
  return dw.u[0] != 0 ? 1 : 0;
}

int main(int argc, char *argv[]) {
  if (test_endianness(argc, argv) != test_endianness_vol(argc, argv))
    abort();
  exit(0);
}
