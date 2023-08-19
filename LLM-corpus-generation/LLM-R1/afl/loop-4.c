// Modification timestamp: 2023-08-14 14:31:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-4.c

#include <stdio.h>
#include <stdlib.h>

int f(long i) {
  int j = 1;
  for (i = -0x70000000L; i < 0x60000000L; i += 0x10000000L) j <<= 1;
  return j;
}

int main(int argc, char *argv[]) {
  if (f(atoi(argv[1])) != 8192)
    abort ();
  exit (0);
}
