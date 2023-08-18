// Modification timestamp: 2023-08-14 16:14:38
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/strct-pack-3.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  short i __attribute__ ((aligned (2), packed));
  int f[2] __attribute__ ((aligned (2), packed));
} A;

int f(A *ap) {
  short i, j = 1;

  i = ap->f[1];
  i += ap->f[j];
  for (j = 0; j < 2; j++)
    i += ap->f[j];

  return i;
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  A a;
  a.f[0] = atoi(argv[1]);
  a.f[1] = atoi(argv[2]);
  
  if (f(&a) != atoi(argv[3])) {
    abort();
  }

  exit(0);
}

//Please make sure to provide the correct values for the command line arguments `<value> <value> <expected_result>` when running the modified program.