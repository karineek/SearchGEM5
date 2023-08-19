// Modification timestamp: 2023-08-14 14:53:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr30185.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

typedef struct S {
  char a;
  long long b;
} S;

S foo(S x, S y) {
  S z;
  z.b = x.b / y.b;
  return z;
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  S a, b;
  a.b = atoll(argv[1]);
  b.b = atoll(argv[2]);

  if (foo(a, b).b != atoll(argv[3])) {
    abort();
  }

  a.b = atoll(argv[4]);
  b.b = atoll(argv[5]);

  if (foo(a, b).b != atoll(argv[6])) {
    abort();
  }

  return 0;
}
