// Modification timestamp: 2023-08-14 12:07:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011223-1.c

#include <stdio.h>
#include <stdlib.h>

extern void exit(int);
extern void abort(void);

static int i;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  i = atoi(argv[1]);
  switch ((signed char) i) {
    case 255:
      abort();
    default:
      exit(0);
  }
}
