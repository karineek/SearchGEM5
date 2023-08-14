// Modification timestamp: 2023-08-14 12:51:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040218-1.c

#include <stdio.h>
#include <stdlib.h>

long int xb(long int *y) __attribute__((__noinline__));
long int xw(long int *y) __attribute__((__noinline__));
short int yb(short int *y) __attribute__((__noinline__));

long int xb(long int *y)
{
  long int xx = *y & 255;
  return xx + y[1];
}

long int xw(long int *y)
{
  long int xx = *y & 65535;
  return xx + y[1];
}

short int yb(short int *y)
{
  short int xx = *y & 255;
  return xx + y[1];
}

int main(int argc, char *argv[])
{
  long int y[] = {atol(argv[1]), atol(argv[2])};
  short int yw[] = {atoi(argv[3]), atoi(argv[4])};

  if (xb(y) != 16255 || xw(y) != 81535 || yb(yw) != 16255)
    abort();
  exit(0);
}

(Note: This code assumes `argv[1]` and `argv[2]` as the values for `y[]` and `argv[3]` and `argv[4]` as the values for `yw[]`. Please replace them with the actual values when using the program.)