// Modification timestamp: 2023-08-14 13:40:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/940122-1.c
C
#include <stdio.h>
#include <stdlib.h>

char *a = 0;
char *b = 0;

void g(int x) {
  if ((!!a) != (!!b))
    abort ();
}

void f(int x) {
  g (x * x);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  f(x);
  exit(0);
}
