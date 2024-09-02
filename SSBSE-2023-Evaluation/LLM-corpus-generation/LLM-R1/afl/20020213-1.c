// Modification timestamp: 2023-08-14 12:10:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020213-1.c

#include <stdio.h>
#include <stdlib.h>

int bar(float x) {
  return 2241;
}

struct A {
  float a1;
  int a2;
} a;

int b;

void foo(int argc, char *argv[]) {
  a.a2 = bar(a.a1);
  a.a2 = a.a2 < atoi(argv[1]) - 1 ? a.a2 : atoi(argv[1]) - 1;
  if (a.a2 >= atoi(argv[1]) - 1) {
    abort();
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  a.a1 = 1.0f;
  b = 3384;
  foo(argc, argv);
  return 0;
}
