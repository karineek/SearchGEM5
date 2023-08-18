// Modification timestamp: 2023-08-14 15:52:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78617.c

#include <stdio.h>
#include <stdlib.h>

int a = 0;
int d = 1;
int f = 1;

int fn1() {
  return a || 1 >> a;
}

int fn2(int p1, int p2) {
  return p2 >= 2 ? p1 : p1 >> 1;
}

int fn3(int p1) {
  return d ^ p1;
}

int fn4(int p1, int p2) {
  return fn3(!d > fn2((f = fn1() - 1000) || p2, p1));
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <p1> <p2>\n", argv[0]);
    return 1;
  }

  int p1 = atoi(argv[1]);
  int p2 = atoi(argv[2]);

  if (fn4(p1, p2) != 1)
    __builtin_abort ();
  return 0;
}
