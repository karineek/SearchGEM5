
// Modification timestamp: 2023-08-10 15:41:28
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  struct s0 a = { 1., 2. };
  f0(atoi(argv[1]), a);
  printf("g0.x: %.4f, g0.y: %.4f\n", (double) g0.x, (double) g0.y);
  return 0;
}
