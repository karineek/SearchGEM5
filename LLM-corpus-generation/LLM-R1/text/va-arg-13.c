// Modification timestamp: 2023-08-14 16:56:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/va-arg-13.c
/* derived from mozilla source code */

#include <stdarg.h>

typedef struct {
  void *stream;
  va_list ap;
  int nChar;
} ScanfState;

void dummy (va_list vap)
{
  if (va_arg (vap, int) != 1234) abort();
  return;
}

void test (int fmt, ...)
{
  ScanfState state, *statep;

  statep = &state;

  va_start (statep->ap, fmt);
  dummy (statep->ap);
  va_end (statep->ap);

  va_start (state.ap, fmt);
  dummy (state.ap);
  va_end (state.ap);

  return;
}

int main (void)
{
  test (456, 1234);
  exit (0);
}
