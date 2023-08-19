// Modification timestamp: 2023-08-14 15:12:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr44164.c

#include <stdio.h>
#include <stdlib.h>

struct Z {
  int i;
};

struct YY {
  struct Z c;
};

struct Y {
  struct YY bb;
};

struct X {
  struct Y b;
} a;

int __attribute__((noinline, noclone)) foo(struct Z *p) {
  int i = p->i;
  a.b = (struct Y){};
  return p->i + i;
}

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  a.b.bb.c.i = atoi(argv[1]);
  if (foo(&a.b.bb.c) != atoi(argv[1])) {
    abort();
  }

  return 0;
}
