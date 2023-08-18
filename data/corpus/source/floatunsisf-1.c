// Modification timestamp: 2023-08-14 14:27:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/floatunsisf-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

#if __INT_MAX__ >= 0x7fffffff
volatile unsigned u;
#else
volatile unsigned long u;
#endif

volatile float f1, f2;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  u = atoi(argv[1]);
  f1 = (float)u;
  f2 = (float)0x80000081;

  if (f1 != f2)
    abort();

  exit(0);
}
