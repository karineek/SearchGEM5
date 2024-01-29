// Modification timestamp: 2023-08-14 15:29:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr57876.c
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
int a, b = 1, c, *d = &c, f, *g, h, j;
static int e;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  for (i = 0; i < 2; i++) {
    long long k = atoi(argv[1]);
    int l;
    for (f = 0; f < 8; f++) {
      int *m = &e;
      j = *d;
      h = a * j - 1;
      *m = (h == 0) < k;
      g = &l;
    }
  }
  if (e != 1)
    abort ();
  return 0;
}