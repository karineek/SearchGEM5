// Modification timestamp: 2023-08-14 15:28:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57875.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
int a[1], b, c, d, f, i;
char e[1];

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = 0;
  
  for (; i < x; i++) {
    if (!d) {
      if (!c)
        f = 2;
      e[0] &= f ^= 0;
    }
  }

  b = a[e[0] >> 1 & y];
  if (b != 0)
    abort();
  return 0;
}
