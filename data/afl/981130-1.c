// Modification timestamp: 2023-08-14 13:51:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/981130-1.c

#include <stdio.h>
#include <stdlib.h>

struct s { int a; int b; };
struct s s1;
struct s s2 = { 1, 2 };

void check(int a, int b) {
  if (a == b)
    exit(0);
  else
    abort();
}

int main(int argc, char *argv[]) {
  int *p;
  int x;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  s1.a = atoi(argv[1]);
  p = &s1.a;
  s1 = s2;
  x = *p;

  check(x, 1);
}
