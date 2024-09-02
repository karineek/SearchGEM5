// Modification timestamp: 2023-08-14 12:51:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040302-1.c

#include <stdio.h>
#include <stdlib.h>

void foo(int x) {
  volatile int b;
  b = 0xffffffff;
}

void bar(int *pc) {
  static const void *l[] = {&&lab0, &&end};

  foo(0);
  goto *l[*pc];
 lab0:
  foo(0);
  pc++;
  goto *l[*pc];
 end:
  return;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int code[] = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5])};
  bar(code);
  return 0;
}
