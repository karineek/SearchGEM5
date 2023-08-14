// Modification timestamp: 2023-08-14 13:51:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/981019-1.c

#include <stdio.h>
#include <stdlib.h>

extern int f2(void);
extern int f3(void);
extern void f1(void);

void ff(int fname, int part, int nparts) {
  if (fname) {
    if (nparts) {
      f1();
    }
  } else {
    fname = atoi(argv[1]);
  }

  while (f3()) {
    if (nparts && f2()) {
      f1();
      nparts = part;
      if (f3()) {
        f1();
      }
      f1();
      break;
    }
  }

  if (nparts) {
    f1();
  }
  return;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <fname> <part> <nparts>\n", argv[0]);
    return 1;
  }

  int fname = atoi(argv[1]);
  int part = atoi(argv[2]);
  int nparts = atoi(argv[3]);

  ff(fname, part, nparts);
  return 0;
}

int f3(void) {
  static int x = 0;
  x = !x;
  return x;
}

void f1(void) {
  abort();
}

int f2(void) {
  abort();
}
