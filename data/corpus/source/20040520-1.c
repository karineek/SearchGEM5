// Modification timestamp: 2023-08-14 12:54:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040520-1.c

#include <stdio.h>
#include <stdlib.h>

void abort ();
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int foo = atoi(argv[1]);
  int bar (void)
  {
    int baz = 0;
    if (foo!=45)
      baz = foo;
    return baz;
  }
  foo = 1;
  if (!bar ())
    abort ();
  return 0;
}
