// Modification timestamp: 2023-08-14 14:54:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr33669.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef struct foo_t {
  unsigned int blksz;
  unsigned int bf_cnt;
} foo_t;

#define _RNDUP(x, unit) ((((x) + (unit) - 1) / (unit)) * (unit))
#define _RNDDOWN(x, unit) ((x) - ((x) % (unit)))

long long foo(foo_t *const pxp, long long offset, unsigned int extent) {
  long long blkoffset = _RNDDOWN(offset, (long long)pxp->blksz);
  unsigned int diff = (unsigned int)(offset - blkoffset);
  unsigned int blkextent = _RNDUP(diff + extent, pxp->blksz);

  if (pxp->blksz < blkextent)
    return -1LL;

  if (pxp->bf_cnt > pxp->blksz)
    pxp->bf_cnt = pxp->blksz;

  return blkoffset;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <blksz> <bf_cnt> <offset>\n", argv[0]);
    return 1;
  }

  foo_t x;
  long long xx;

  x.blksz = atoi(argv[1]);
  x.bf_cnt = atoi(argv[2]);
  xx = foo(&x, atoll(argv[3]), 4096);
  if (xx != 0LL)
    abort();
  return 0;
}
