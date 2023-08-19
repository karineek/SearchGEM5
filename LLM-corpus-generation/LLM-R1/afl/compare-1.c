// Modification timestamp: 2023-08-14 14:17:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/compare-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int ieq(int x, int y, int ok) {
  if ((x <= y) && (x >= y)) {
    if (!ok)
      abort();
  } else if (ok) {
    abort();
  }

  if ((x <= y) && (x == y)) {
    if (!ok)
      abort();
  } else if (ok) {
    abort();
  }

  if ((x <= y) && (y <= x)) {
    if (!ok)
      abort();
  } else if (ok) {
    abort();
  }

  if ((y == x) && (x <= y)) {
    if (!ok)
      abort();
  } else if (ok) {
    abort();
  }
}

int ine(int x, int y, int ok) {
  if ((x < y) || (x > y)) {
    if (!ok)
      abort();
  } else if (ok) {
    abort();
  }
}

int ilt(int x, int y, int ok) {
  if ((x < y) && (x != y)) {
    if (!ok)
      abort();
  } else if (ok) {
    abort();
  }
}

int ile(int x, int y, int ok) {
  if ((x < y) || (x == y)) {
    if (!ok)
      abort();
  } else if (ok) {
    abort();
  }
}

int igt(int x, int y, int ok) {
  if ((x > y) && (x != y)) {
    if (!ok)
      abort();
  } else if (ok) {
    abort();
  }
}

int ige(int x, int y, int ok) {
  if ((x > y) || (x == y)) {
    if (!ok)
      abort();
  } else if (ok) {
    abort();
  }
}

int main(int argc, char *argv[]) {
  int arg1 = atoi(argv[1]);
  int arg2 = atoi(argv[2]);
  int arg3 = atoi(argv[3]);

  ieq(arg1, arg2, arg3);
  ine(arg1, arg2, arg3);
  ilt(arg1, arg2, arg3);
  ile(arg1, arg2, arg3);
  igt(arg1, arg2, arg3);
  ige(arg1, arg2, arg3);

  return 0;
}

Note: Please make sure to pass three integer arguments when running the program.