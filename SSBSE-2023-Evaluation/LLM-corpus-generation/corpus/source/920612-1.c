// Modification timestamp: 2023-08-14 13:28:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920612-1.c

/* { dg-options "-fwrapv" } */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

int f(int j) { return ++j > 0; }

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int j = atoi(argv[1]);
  if (f(j)) abort();
  exit(0);
}
