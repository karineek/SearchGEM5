// Modification timestamp: 2023-08-14 12:00:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010904-1.c

#include <stdio.h>
#include <stdlib.h>

#ifdef __pdp11__
#define alignment 2
#else
#define alignment 32
#endif

typedef struct x { int a; int b; } __attribute__((aligned(alignment))) X;
typedef struct y { X x[32]; int c; } Y;

Y y[2];

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (((char *)&y[1] - (char *)&y[0]) & 31)
    abort ();
  exit (0);
}
