// Modification timestamp: 2023-08-14 12:42:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030218-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort ();
extern void exit (int);

short *q;

long foo (short *p) {
  long b = *p;
  q = p + 1;
  return b;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  short a = (short)atoi(argv[1]);
  if (foo(&a) != (long)(short)atoi(argv[2])) {
    abort();
  }
  exit(0);
}

