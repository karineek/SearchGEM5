// Modification timestamp: 2023-08-14 13:35:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930718-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct rtx_def {
  int f1: 1;
  int f2: 1;
} *rtx;

static rtx f(rtx orig) {
  if (orig->f1 || orig->f2) {
    return orig;
  }
  orig->f2 = 1;
  return orig;
}

void f2() {
  abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  struct rtx_def foo;
  rtx bar;
  
  foo.f1 = atoi(argv[1]);
  foo.f2 = 0;
  bar = f(&foo);
  
  if (bar != &foo || bar->f2 != 0) {
    abort();
  }
  
  exit(0);
}
