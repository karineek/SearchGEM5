// Modification timestamp: 2023-08-14 13:43:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/951115-1.c

#include <stdio.h>
#include <stdlib.h>

int var = 0;

void g() {
  var = 1;
}

void f() {
  int f2 = 0;

  if (f2 == 0)
    ;

  g();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  f();
  if (var != atoi(argv[1]))
    abort();
  exit(0);
}
