// Modification timestamp: 2023-08-14 13:31:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/921104-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  unsigned long val = 1;

  if (val > (unsigned long) ~0)
    abort();
  exit (0);
}
