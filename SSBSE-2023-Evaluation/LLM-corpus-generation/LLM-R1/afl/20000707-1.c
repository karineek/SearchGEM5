
// Modification timestamp: 2023-08-10 16:38:18
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/tramp3d-v4/tramp3d-v4.c

#include <stdlib.h>

struct baz {
  int a, b, c;
};

void foo (int a, int b, int c) {
  if (a != 4)
    abort ();
}

void bar (struct baz x, int b, int c) {
  foo (x.b, b, c);
}

int main (int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }

  struct baz x;
  x.a = atoi(argv[1]);
  x.b = atoi(argv[2]);
  x.c = atoi(argv[3]);

  bar (x, 1, 2);
  exit (0);
}
