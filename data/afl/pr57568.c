// Modification timestamp: 2023-08-14 15:28:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57568.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int a[6][9] = {}, b = 1, *c = &a[3][5];

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  if (b && (*c = *c + *c))
    abort();
  return x;
}
