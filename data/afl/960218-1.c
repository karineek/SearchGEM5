// Modification timestamp: 2023-08-14 13:44:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960218-1.c

#include <stdio.h>
#include <stdlib.h>

int glob;

int g(int x) {
  glob = x;
  return 0;
}

void f(int x) {
  int a = ~x;
  while (a)
    a = g(a);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg1 = atoi(argv[1]);

  f(arg1);
  if (glob != -4)
    abort();
  exit(0);
}
