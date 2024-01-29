// Modification timestamp: 2023-08-14 16:14:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/strct-pack-2.c

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  short a __attribute__ ((aligned (2),packed));
  short *ap[2]  __attribute__ ((aligned (2),packed));
} A;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  short i;
  short j = atoi(argv[1]);
  A a, *ap = &a;
  ap->ap[j] = &i;
  exit (0);
}

