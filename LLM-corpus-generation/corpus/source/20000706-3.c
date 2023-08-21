
// Modification timestamp: 2023-08-10 16:37:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000706-3.c
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

extern void abort(void);
extern void exit(int);

int c;
int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  void baz(int *p)
  {
    c = *p;
  }

  void bar(int b)
  {
    if (c != 1 || b != 2)
      abort();
  }

  void foo(int a, int b)
  {
    baz(&a);
    bar(b);
  }

  foo(a, b);
  exit(0);
}
