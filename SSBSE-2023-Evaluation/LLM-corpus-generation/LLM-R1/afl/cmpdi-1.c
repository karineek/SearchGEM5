// Modification timestamp: 2023-08-14 14:14:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/cmpdi-1.c

#include <stdio.h>
#include <stdlib.h>

#define F 140
#define T 13

int feq(long long int x, long long int y) {
  if (x == y)
    return T;
  else
    return F;
}

int fne(long long int x, long long int y) {
  if (x != y)
    return T;
  else
    return F;
}

int flt(long long int x, long long int y) {
  if (x < y)
    return T;
  else
    return F;
}

int fge(long long int x, long long int y) {
  if (x >= y)
    return T;
  else
    return F;
}

int fgt(long long int x, long long int y) {
  if (x > y)
    return T;
  else
    return F;
}

int fle(long long int x, long long int y) {
  if (x <= y)
    return T;
  else
    return F;
}

int fltu(unsigned long long int x, unsigned long long int y) {
  if (x < y)
    return T;
  else
    return F;
}

int fgeu(unsigned long long int x, unsigned long long int y) {
  if (x >= y)
    return T;
  else
    return F;
}

int fgtu(unsigned long long int x, unsigned long long int y) {
  if (x > y)
    return T;
  else
    return F;
}

int fleu(unsigned long long int x, unsigned long long int y) {
  if (x <= y)
    return T;
  else
    return F;
}

long long args[] = {
  0LL,
  1LL,
  -1LL,
  0x7fffffffffffffffLL,
  0x8000000000000000LL,
  0x8000000000000001LL,
  0x1A3F237394D36C58LL,
  0x93850E92CAAC1B04LL
};

int correct_results[] = {
  T, F, F, T, F, T, F, T, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, F, T, T, F,
  T, F, F, T, F, T, F, T, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, F, T, T, F,
  T, F, F, T, F, T, F, T, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, T, F, F, T, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, T, F, F, T,
  T, F, F, T, F, T, F, T, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  T, F, F, T, F, T, F, T, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  T, F, F, T, F, T, F, T, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, F, T, T, F,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, F, T, T, F, T, F, F, T,
  T, F, F, T, F, T, F, T, F, T,
  F, T, F, T, T, F, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, F, T, T, F,
  F, T, T, F, F, T, T, F, F, T,
  F, T, T, F, F, T, F, T, T, F
};

int main() {
  int i, j, *res = correct_results;

  for (i = 0; i < 8; i++) {
    long long arg0 = args[i];
    for (j = 0; j < 8; j++) {
      long long arg1 = args[j];

      if (feq(arg0, arg1) != *res++)
        abort();
      if (fne(arg0, arg1) != *res++)
        abort();
      if (flt(arg0, arg1) != *res++)
        abort();
      if (fge(arg0, arg1) != *res++)
        abort();
      if (fgt(arg0, arg1) != *res++)
        abort();
      if (fle(arg0, arg1) != *res++)
        abort();
      if (fltu(arg0, arg1) != *res++)
        abort();
      if (fgeu(arg0, arg1) != *res++)
        abort();
      if (fgtu(arg0, arg1) != *res++)
        abort();
      if (fleu(arg0, arg1) != *res++)
        abort();
    }
  }
  exit(0);
}


Note: I've added missing semicolons in the code.