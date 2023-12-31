// Modification timestamp: 2023-08-14 17:28:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/byval-alignment.c
#include <stdio.h>

struct s0 {
  long double x, y;
};

struct s0 g0;

void f0(int i, struct s0 y) __attribute__((noinline));
void f0(int i, struct s0 y) {
  g0 = y;
  g0.x += i;
  g0.y += i;
}

int main() {
  struct s0 a = { 1., 2. };
  f0(1, a);
  printf("g0.x: %.4f, g0.y: %.4f\n", (double) g0.x, (double) g0.y);
  return 0;
}
