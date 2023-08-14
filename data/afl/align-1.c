// Modification timestamp: 2023-08-14 13:59:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/align-1.c

#include <stdio.h>
#include <stdlib.h>

typedef int new_int __attribute__ ((aligned(16)));
struct S { int x; };

int main(int argc, char *argv[]) {
  if (sizeof(struct S) != sizeof(new_int))
    abort();
  return 0;
}
