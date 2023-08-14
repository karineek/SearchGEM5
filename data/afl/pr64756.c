// Modification timestamp: 2023-08-14 15:41:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr64756.c

#include <stdio.h>
#include <stdlib.h>

int a, *tmp, **c = &tmp;
volatile int d;
static int *volatile *e = &tmp;
unsigned int f;

static void fn1(int *p) {
  int g;
  for (; f < atoi(argv[1]); f++) {
    for (g = atoi(argv[2]); g >= 0; g--) {
      d || d;
      *c = p;

      if (tmp != &a)
        __builtin_abort();

      *e = atoi(argv[3]);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }

  fn1(&a);
  return 0;
}
