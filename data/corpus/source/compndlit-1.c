// Modification timestamp: 2023-08-14 14:19:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/compndlit-1.c

#include <stdio.h>
#include <stdlib.h>

#if __INT_MAX__ < 2147483647
int main(void) {
  exit(0);
}
#else
struct S {
  int a:3;
  unsigned b:1, c:28;
};

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int value = atoi(argv[1]);

  struct S x = {1, 1, 1};

  x = (struct S){b: 0, a: 0, c: ({ struct S o = x; o.a == 1 ? value : 20; })};
  if (x.c != value)
    abort();
  exit(0);
}
#endif
