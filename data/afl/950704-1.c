// Modification timestamp: 2023-08-14 13:42:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950704-1.c

#include <stdio.h>
#include <stdlib.h>

int errflag;

long long f(long long x, long long y) {
  long long r;

  errflag = 0;
  r = x + y;
  if (x >= 0) {
    if ((y < 0) || (r >= 0))
      return r;
  } else {
    if ((y > 0) || (r < 0))
      return r;
  }
  errflag = 1;
  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  f(0, 0);
  if (errflag)
    abort();

  f(1, -1);
  if (errflag)
    abort();

  f(-1, 1);
  if (errflag)
    abort();

  long long arg1 = atoll(argv[1]);
  long long arg2 = atoll(argv[2]);

  f(0x8000000000000000LL, 0x8000000000000000LL);
  if (!errflag)
    abort();

  f(0x8000000000000000LL, -1LL);
  if (!errflag)
    abort();

  f(0x7fffffffffffffffLL, 0x7fffffffffffffffLL);
  if (!errflag)
    abort();

  f(0x7fffffffffffffffLL, 1LL);
  if (!errflag)
    abort();

  f(0x7fffffffffffffffLL, 0x8000000000000000LL);
  if (errflag)
    abort();

  exit(0);
}

