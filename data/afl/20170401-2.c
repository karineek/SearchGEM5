// Modification timestamp: 2023-08-14 13:23:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20170401-2.c

#include <stdio.h>
#include <stdlib.h>

void adjust_xy(short *, short *);

struct adjust_template {
  short kx_x;
  short kx_y;
};

static struct adjust_template adjust = {1, 1};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  short x = atoi(argv[1]);
  short y = atoi(argv[2]);

  adjust_xy(&x, &y);

  if (x != 2) {
    abort();
  }

  exit(0);
}

void adjust_xy(short *x, short *y) {
  *x = adjust.kx_x * *x + adjust.kx_y * *y;
}

