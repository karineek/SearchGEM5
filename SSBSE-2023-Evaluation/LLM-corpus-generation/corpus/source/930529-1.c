// Modification timestamp: 2023-08-14 13:33:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930529-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

int dd(int x, int d) {
  return x / d;
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  int i;
  for (i = -3; i <= 3; i++) {
    if (dd(i, 1) != i / 1)
      abort();
    if (dd(i, 2) != i / 2)
      abort();
    if (dd(i, 3) != i / 3)
      abort();
    if (dd(i, 4) != i / 4)
      abort();
    if (dd(i, 5) != i / 5)
      abort();
    if (dd(i, 6) != i / 6)
      abort();
    if (dd(i, 7) != i / 7)
      abort();
    if (dd(i, 8) != i / 8)
      abort();
  }
  for (i = ((unsigned)~0 >> 1) - 3; i <= ((unsigned)~0 >> 1) + 3; i++) {
    if (dd(i, 1) != i / 1)
      abort();
    if (dd(i, 2) != i / 2)
      abort();
    if (dd(i, 3) != i / 3)
      abort();
    if (dd(i, 4) != i / 4)
      abort();
    if (dd(i, 5) != i / 5)
      abort();
    if (dd(i, 6) != i / 6)
      abort();
    if (dd(i, 7) != i / 7)
      abort();
    if (dd(i, 8) != i / 8)
      abort();
  }
  exit(0);
}
