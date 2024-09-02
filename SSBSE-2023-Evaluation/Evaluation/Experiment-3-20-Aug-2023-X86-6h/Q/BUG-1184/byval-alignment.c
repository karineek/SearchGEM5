// Modification timestamp: 2023-08-14 17:28:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/byval-alignment.c
#include <stdlib.h>

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

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  struct s0 a = { (long double)atof(argv[1]), (long double)atof(argv[2]) };
  f0(1, a);
  printf("g0.x: %.4Lf, g0.y: %.4Lf\n", g0.x, g0.y);
  return 0;
}


//Please note that the `argv[1]` and `argv[2]` are converted to `long double` using `atof()` function. Also, the format specifier `%Lf` is used to print the values of `g0.x` and `g0.y`.