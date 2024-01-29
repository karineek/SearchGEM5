
// Modification timestamp: 2023-08-10 16:41:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/Trimaran/20000726-1.c

#include <stdlib.h>

void adjust_xy (short *, short *);

struct adjust_template
{
  short kx_x;
  short kx_y;
  short kx;
  short kz;
};

static struct adjust_template adjust = {0, 0, 1, 1};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  short x = atoi(argv[1]);
  short y = atoi(argv[2]);

  adjust_xy (&x, &y);

  if (x != 1)
    abort ();

  exit (0);
}

void
adjust_xy (x, y)
     short  *x;
     short  *y;
{
  *x = adjust.kx_x * *x + adjust.kx_y * *y + adjust.kx;
}
