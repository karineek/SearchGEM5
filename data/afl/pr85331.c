// Modification timestamp: 2023-08-14 16:01:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr85331.c

#include <stdio.h>
#include <stdlib.h>

typedef double V __attribute__((vector_size(2 * sizeof(double))));
typedef long long W __attribute__((vector_size(2 * sizeof(long long)))));

__attribute__((noipa)) void foo(V* r) {
  V y = {0.0, 0.0};
  W m = {0LL, 0LL};
  *r = __builtin_shuffle(y, m);
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  V r;
  foo(&r);
  if (r[0] != 2.0 || r[1] != 1.0) {
    printf("Incorrect result\n");
    return 1;
  }

  return 0;
}

