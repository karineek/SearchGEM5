// Modification timestamp: 2023-08-14 11:53:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001024-1.c

#include <stdio.h>
#include <stdlib.h>

struct a;

extern int baz(struct a *__restrict x);

struct a {
  long v;
  long w;
};

struct b {
  struct a c;
  struct a d;
};

int bar(int x, const struct b *__restrict y, struct b *__restrict z) {
  if (y->c.v || y->c.w != 250000 || y->d.v || y->d.w != 250000)
    abort();
}

void foo(int argc, char *argv[]) {
  struct b x;
  x.c.v = atoi(argv[1]);
  x.c.w = atoi(argv[2]);
  x.d = x.c;
  bar(0, &x, NULL);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  foo(argc, argv);
  exit(0);
}
