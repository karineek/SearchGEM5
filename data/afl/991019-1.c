// Modification timestamp: 2023-08-14 13:56:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/991019-1.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double epsilon;
} material_type;

material_type foo(double x)
{
  material_type m;

  m.epsilon = 1.0 + x;
  return m;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  material_type x;

  for (i = 0; i < atoi(argv[1]); i++) {
    x = foo(1.0);
    if (x.epsilon != 1.0 + 1.0)
      abort();
  }

  exit(0);
}
