// Modification timestamp: 2023-08-14 12:52:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040313-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int main(int argc, char *argv[]) {
  int t[1025] = { argc }, d;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  d = 0;
  d = t[d]++;
  if (t[0] != atoi(argv[1]))
    abort();
  if (d != atoi(argv[2]))
    abort();
  return 0;
}
