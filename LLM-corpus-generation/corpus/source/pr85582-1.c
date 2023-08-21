// Modification timestamp: 2023-08-14 16:01:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr85582-1.c
#include <stdlib.h>

#include <stdio.h>

int a, b, d = 2, e;
long long c = 1;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int g = atoi(argv[1]);
L1:
  e = d;
  if (a)
    goto L1;
  g--;
  int i = c >> ~(~e | ~g);
L2:
  c = (b % c) * i;
  if (!e)
    goto L2;
  return 0;
}
