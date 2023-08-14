// Modification timestamp: 2023-08-14 12:58:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040831-1.c

#include <stdlib.h>

void abort(void);
void exit(int);

int main(int argc, char *argv[]) {
  double d = atof(argv[1]);
  long l = (d > 10000) ? (unsigned long) d : (long) d;
  if (l != -12)
    abort();
  exit(0);
}
