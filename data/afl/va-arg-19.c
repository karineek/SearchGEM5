// Modification timestamp: 2023-08-14 16:57:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-19.c

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

typedef int TYPE;

void vafunction (char *dummy, ...)
{
  va_list ap;

  va_start(ap, dummy);
  if (va_arg (ap, TYPE) != atoi(argv[1]))
    abort();
  if (va_arg (ap, TYPE) != atoi(argv[2]))
    abort();
  if (va_arg (ap, TYPE) != atoi(argv[3]))
    abort();
  if (va_arg (ap, TYPE) != atoi(argv[4]))
    abort();
  if (va_arg (ap, TYPE) != atoi(argv[5]))
    abort();
  if (va_arg (ap, TYPE) != atoi(argv[6]))
    abort();
  if (va_arg (ap, TYPE) != atoi(argv[7]))
    abort();
  if (va_arg (ap, TYPE) != atoi(argv[8]))
    abort();
  if (va_arg (ap, TYPE) != atoi(argv[9]))
    abort();
  va_end(ap);
}

int main(int argc, char *argv[]) {
  if (argc < 10) {
    printf("Usage: %s <1> <2> <3> <4> <5> <6> <7> <8> <9>\n", argv[0]);
    return 1;
  }

  vafunction( "", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]), atoi(argv[8]), atoi(argv[9]) );
  exit(0);
  return 0;
}
