// Modification timestamp: 2023-08-14 15:39:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr63209.c

#include <stdio.h>
#include <stdlib.h>

static int Sub(int a, int b) {
  return b - a;
}

static unsigned Select(unsigned a, unsigned b, unsigned c) {
  const int pa_minus_pb =
      Sub((a >>  8) & 0xff, (b >>  8) & 0xff) +
      Sub((a >>  0) & 0xff, (b >>  0) & 0xff);
  return (pa_minus_pb <= 0) ? a : b;
}

__attribute__((noinline)) unsigned Predictor(unsigned left, const unsigned* const top) {
  const unsigned pred = Select(top[1], left, top[0]);
  return pred;
}

int main(int argc, char *argv[]) {
  const unsigned top[2] = {atoi(argv[1]), atoi(argv[2])};
  const unsigned left = atoi(argv[3]);
  const unsigned pred = Predictor(left, top + 1);
  if (pred == left)
    return 0;
  return 1;
}
