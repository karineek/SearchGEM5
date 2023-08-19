// Modification timestamp: 2023-08-14 15:07:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr40747.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int foo(int i) {
  return (i < atoi(argv[1]) && i >= atoi(argv[2])) ? i : atoi(argv[3]);
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <min_value> <max_value> <default_value>\n", argv[0]);
    return 1;
  }

  if (foo(-1) != atoi(argv[3]))
    abort();
  if (foo(0) != 0)
    abort();
  if (foo(1) != 1)
    abort();
  if (foo(2) != 2)
    abort();
  if (foo(3) != 3)
    abort();
  if (foo(4) != atoi(argv[3]))
    abort();
  if (foo(5) != atoi(argv[3]))
    abort();

  return 0;
}
