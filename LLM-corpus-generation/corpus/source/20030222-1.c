// Modification timestamp: 2023-08-14 12:43:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030222-1.c

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void ll_to_int(long long x, volatile int *p) {
  int i;
  asm ("" : "=r" (i) : "0" (x));
  *p = i;
}

int val = INT_MIN + 1;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  volatile int i;
  ll_to_int((long long)atoi(argv[1]), &i);
  if (i != atoi(argv[1]))
    abort ();

  exit(0);
}
