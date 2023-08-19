// Modification timestamp: 2023-08-14 15:25:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr55875.c

#include <stdio.h>
#include <stdlib.h>

int a[251];

__attribute__ ((noinline))
t(int i)
{
  if (i == 0)
    exit(0);
  if (i > 255)
    abort();
}

int main(int argc, char *argv[]) {
  unsigned int i;

  for (i = 0;; i++) {
    if (i >= 251) {
      printf("Index out of bounds\n");
      return 1;
    }

    a[i] = t((unsigned char)(i + 5));
  }

  return 0;
}

