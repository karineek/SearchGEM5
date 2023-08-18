// Modification timestamp: 2023-08-14 15:17:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr48814-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int arr[] = {1, 2, 3, 4};
int count = 0;

int incr(void) {
  return ++count;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  arr[x++] = incr();
  if (x != 2 || arr[x] != 3)
    abort();
  return 0;
}
