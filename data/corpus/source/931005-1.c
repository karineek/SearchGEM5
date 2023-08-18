// Modification timestamp: 2023-08-14 13:39:01
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/931005-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char x;
} T;

T f(T s1) {
  T s1a;
  s1a.x = s1.x;
  return s1a;
}

int main(int argc, char *argv[]) {
  T s1a, s1b;
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  s1a.x = atoi(argv[1]);
  s1b = f(s1a);
  if (s1b.x != atoi(argv[1])) {
    abort();
  }
  exit(0);
}
