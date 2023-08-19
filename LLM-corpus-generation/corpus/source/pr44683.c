// Modification timestamp: 2023-08-14 15:13:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr44683.c

#include <stdio.h>
#include <stdlib.h>

int copysign_bug(double x) {
  if (x != 0.0 && (x * 0.5 == x))
    return 1;
  if (__builtin_copysign(1.0, x) < 0.0)
    return 2;
  else
    return 3;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  double x = atof(argv[1]);
  if (copysign_bug(x) != 2)
    abort();
  
  return 0;
}
