// Modification timestamp: 2023-08-14 13:17:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20100316-1.c

#include <stdio.h>

struct Foo {
  int i;
  unsigned precision : 10;
  unsigned blah : 3;
} f;

int foo(struct Foo *p) {
  struct Foo *q = p;
  return (*q).precision;
}

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }

  f.i = atoi(argv[1]);
  f.precision = atoi(argv[2]);
  f.blah = atoi(argv[3]);

  if (foo(&f) != 0)
    abort();
  return 0;
}
