// Modification timestamp: 2023-08-14 14:57:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr35231.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int __attribute__((noinline))
foo(int bits_per_pixel, int depth)
{
  if ((bits_per_pixel | depth) == 1)
    abort ();
  return bits_per_pixel;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <bits_per_pixel> <depth>\n", argv[0]);
    return 1;
  }

  int bits_per_pixel = atoi(argv[1]);
  int depth = atoi(argv[2]);

  if (foo(bits_per_pixel, depth) != bits_per_pixel)
    abort ();

  return 0;
}
