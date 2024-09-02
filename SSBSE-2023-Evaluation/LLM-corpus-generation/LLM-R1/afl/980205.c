// Modification timestamp: 2023-08-14 13:48:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980205.c

#include <stdarg.h>
#include <stdlib.h>

void fdouble(double one, ...) {
  double value;
  va_list ap;

  va_start(ap, one);
  value = va_arg(ap, double);
  va_end(ap);

  if (one != atof(argv[1]) || value != atof(argv[2])) {
    abort();
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <one> <value>\n", argv[0]);
    return 1;
  }

  fdouble(atof(argv[1]), atof(argv[2]));
  exit(0);
}
