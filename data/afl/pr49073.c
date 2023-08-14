// Modification timestamp: 2023-08-14 15:17:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49073.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int a[] = {atoi(argv[1]), 2, 3, 4, 5, 6, 7};
  int c;

  int d = 1, i = 1;
  _Bool f = 0;
  do {
    d = a[i];
    if (f && d == 4) {
      ++c;
      break;
    }
    i++;
    f = (d == 3);
  } while (d < 7);

  if (c != 1)
    abort();

  return 0;
}
