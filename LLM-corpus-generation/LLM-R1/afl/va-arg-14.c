// Modification timestamp: 2023-08-14 16:56:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-14.c

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

va_list global;

void vat(va_list param, ...)
{
  va_list local;

  va_start(local, param);
  va_copy(global, local);
  va_copy(param, local);
  if (va_arg(local, int) != 1)
    abort();
  va_end(local);
  if (va_arg(global, int) != 1)
    abort();
  va_end(global);
  if (va_arg(param, int) != 1)
    abort();
  va_end(param);

  va_start(param, param);
  va_start(global, param);
  va_copy(local, param);
  if (va_arg(local, int) != 1)
    abort();
  va_end(local);
  va_copy(local, global);
  if (va_arg(local, int) != 1)
    abort();
  va_end(local);
  if (va_arg(global, int) != 1)
    abort();
  va_end(global);
  if (va_arg(param, int) != 1)
    abort();
  va_end(param);
}

int main(int argc, char *argv[]) {
  va_list t;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  vat(t, atoi(argv[1]));
  exit(0);
}
