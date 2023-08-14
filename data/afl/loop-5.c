// Modification timestamp: 2023-08-14 14:32:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-5.c

#include <stdio.h>
#include <stdlib.h>

static int ap(int i);
static void testit(int n, int m, int ir[]);
static int t = 0;
static int a[4];

static int ap(int i) {
  if (t > 3)
    abort();
  a[t++] = i;
  return 1;
}

static void testit(int n, int m, int ir[]) {
  int ix;

  for (ix = 1; ix <= 4; ix++) {
    if (n == 1)
      m = 4;
    else
      m = n - 1;
    ap(ir[n - 1]);
    n = m;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int ir[4] = {0, 1, 2, 3};
  int n = atoi(argv[1]);
  int m = 3;

  testit(n, m, ir);

  if (a[0] != 0)
    abort();
  if (a[1] != 3)
    abort();
  if (a[2] != 2)
    abort();
  if (a[3] != 1)
    abort();

  exit(0);
}
