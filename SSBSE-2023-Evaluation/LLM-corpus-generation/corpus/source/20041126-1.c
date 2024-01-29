// Modification timestamp: 2023-08-14 12:59:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041126-1.c

#include <stdio.h>
#include <stdlib.h>

extern int abs (int);
extern void abort (void);

void check(int *p) {
  int i;
  for (i = 0; i < 5; ++i)
    if (p[i])
      abort();
  for (; i < 10; ++i)
    if (p[i] != i + 1)
      abort();
}

int main(int argc, char *argv[]) {
  int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int i;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  for (i = -5; i < 0; i++)
    a[abs(i - 10) - 11] = atoi(argv[1]);
  check(a);
  return 0;
}
