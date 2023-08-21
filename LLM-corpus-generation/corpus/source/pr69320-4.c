// Modification timestamp: 2023-08-14 15:48:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr69320-4.c
#include <stdio.h>

#include <stdlib.h>

int a;
char b, d;
short c;
short fn1(int p1, int p2) { return p2 >= 2 ? p1 : p1 > p2; }

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int *e = &a, *f = &a;
  b = atoi(argv[1]);
  for (; b <= 9; b++) {
    c = *e != 5 || d;
    *f = fn1(c || b, a);
  }
  if ((long long) a != 1)
    abort ();
  exit (0);
}
