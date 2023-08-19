// Modification timestamp: 2023-08-14 17:24:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2009-12-07-StructReturn.c

#include <stdio.h>
#include <stdlib.h>

extern int printf(const char * __restrict, ...);
extern void abort(void);

typedef struct {
  float ary[3];
} foostruct;

typedef struct {
  foostruct foo;
  float safe;
} barstruct;

barstruct bar_ary[4];

float * __attribute__ ((__noinline__))
spooky(int i) {
  bar_ary[i].safe = 142.0;
  return &bar_ary[i].safe;
}

foostruct __attribute__ ((__noinline__))
foobify(void) {
  static barstruct my_static_foo = { {42.0, 42.0, 42.0}, /*safe=*/42.0 };
  return my_static_foo.foo;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  float *pf = spooky(0);
  bar_ary[0].foo = foobify();
  if (*pf != 142.0) {
    printf("error: store clobbered memory outside destination\n");
    abort();
  }
  return 0;
}
