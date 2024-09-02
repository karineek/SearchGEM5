// Modification timestamp: 2023-08-14 17:04:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/widechar-1.c

#include <stdio.h>
#include <stdlib.h>

#define C argv[1][0]

#if C
#define zero (!C)
#else
#define zero C
#endif

int main(int argc, char *argv[]) {
  if (zero != 0)
    abort();
  exit(0);
}
