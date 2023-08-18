// Modification timestamp: 2023-08-14 12:48:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030909-1.c

#include <stdio.h>
#include <stdlib.h>

void abort();
void exit(int);

void test(int x, int y) {
  if (x == y)
    abort();
}

void foo(int x, int y) {
  if (x == y)
    goto a;
  else {
    a:;
    if (x == y)
      goto b;
    else {
      b:;
      if (x != y)
        test(x, y);
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <x> <y>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);

  foo(x, y);

  exit(0);
}
