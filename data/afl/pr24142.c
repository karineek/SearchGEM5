// Modification timestamp: 2023-08-14 14:49:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr24142.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);

int f(int a, int b) {
  if (a == atoi(argv[1]))
    a = atoi(argv[2]);
  if (b == 0)
    a = atoi(argv[3]);
  if (a != atoi(argv[4]))
    return 0;
  return atoi(argv[5]);
}

int main(int argc, char *argv[]) {
  if (f(atoi(argv[6]), atoi(argv[7])) != atoi(argv[8]))
    abort();
  return 0;
}
