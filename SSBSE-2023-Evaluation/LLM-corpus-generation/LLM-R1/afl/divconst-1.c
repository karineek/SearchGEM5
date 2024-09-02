// Modification timestamp: 2023-08-14 14:25:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/divconst-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned a, b, c, d;
} t1;

void f(t1 *ps) {
  ps->a = atoi(argv[1]);
  ps->b = ps->a / 3;
  ps->c = atoi(argv[2]);
  ps->d = ps->c / 3;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  t1 s;
  f(&s);
  if (s.a != atoi(argv[1]) || s.b != (atoi(argv[1]) / 3) || s.c != atoi(argv[2]) || s.d != (atoi(argv[2]) / 3))
    abort();
  exit(0);
}
