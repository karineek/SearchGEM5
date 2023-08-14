// Modification timestamp: 2023-08-14 14:30:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-15.c

#include <stdio.h>
#include <stdlib.h>

void foo(unsigned long *start, unsigned long *end) {
  unsigned long *temp = end - 1;

  while (end > start)
    *end-- = *temp--;
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  unsigned long a[5];
  int start, end, k;

  for (start = 0; start < 5; start++)
    for (end = 0; end < 5; end++) {
      for (k = 0; k < 5; k++)
        a[k] = k;

      foo(a + start, a + end);

      for (k = 0; k <= start; k++)
        if (a[k] != k)
          abort();

      for (k = start + 1; k <= end; k++)
        if (a[k] != k - 1)
          abort();

      for (k = end + 1; k < 5; k++)
        if (a[k] != k)
          abort();
    }

  return 0;
}

