// Modification timestamp: 2023-08-14 15:50:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr70903.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char V8 __attribute__ ((vector_size (32)));
typedef unsigned int V32 __attribute__ ((vector_size (32)));
typedef unsigned long long V64 __attribute__ ((vector_size (32)));

static V32 __attribute__ ((noinline, noclone))
foo (V64 x)
{
  V64 y = (V64)(V8){((V8)(V64){65535, x[0]})[1]};
  return (V32){y[0], 255};
}

int main(int argc, char *argv[]) {
  V32 x = foo((V64){});

  if (x[1] != 255) {
    printf("Error: x[1] is not equal to 255\n");
    return 1;
  }

  return 0;
}
