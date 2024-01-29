// Modification timestamp: 2023-08-14 12:09:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020118-1.c

#include <stdlib.h>

extern void exit(int);

volatile signed char *q;
volatile signed int n;

void foo(signed char *p) {
  for (;;) {
    n = p[2];
    n = p[2];
    n = p[2];
    n = p[2];
    n = p[2];
    n = p[2];
    n = p[2];
    n = p[2];
    n = p[2];
    n = p[2];
    n = p[2];
  }
}

int main(int argc, char *argv[]) {
  exit(0);
}

