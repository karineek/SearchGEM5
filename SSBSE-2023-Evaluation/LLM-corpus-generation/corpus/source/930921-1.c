// Modification timestamp: 2023-08-14 13:35:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930921-1.c

#include <stdio.h>
#include <stdlib.h>

unsigned f(unsigned x) {
  return (unsigned) (((unsigned long long) x * 0xAAAAAAAB) >> 32) >> 1;
}

int main(int argc, char *argv[]) {
  unsigned i;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned limit = atoi(argv[1]);

  for (i = 0; i < limit; i++) {
    if (f(i) != i / 3) {
      abort();
    }
  }

  exit(0);
}
