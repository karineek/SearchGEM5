// Modification timestamp: 2023-08-14 14:34:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/mayalias-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

typedef short __attribute__((__may_alias__)) short_a;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  short_a *b = (short_a*) &a;

  b[1] = 0;

  if (a == atoi("0x12345678"))
    abort();

  exit(0);
}
