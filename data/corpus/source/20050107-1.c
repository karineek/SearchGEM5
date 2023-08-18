// Modification timestamp: 2023-08-14 13:01:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050107-1.c

#include <stdio.h>
#include <stdlib.h>

typedef enum { C = 1, D = 2 } B;

extern void abort(void);

struct S {
  B __attribute__((mode(byte))) a;
  B __attribute__((mode(byte))) b;
};

void foo(struct S *x) {
  if (x->a != C || x->b != D)
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  struct S s;
  s.a = atoi(argv[1]);
  s.b = atoi(argv[2]);
  foo(&s);
  return 0;
}
