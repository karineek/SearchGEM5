// Modification timestamp: 2023-08-14 17:04:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/wchar_t-1.c

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

typedef __WCHAR_TYPE__ wchar_t;
extern void abort (void);
extern void exit (int);

int main(int argc, char *argv[]) {
  wchar_t x[] = L"√Ñ";
  wchar_t y = L'√Ñ';

  if (sizeof (x) / sizeof (wchar_t) != 2)
    abort ();
  if (x[0] != L'√Ñ' || x[1] != L'\0')
    abort ();
  if (y != L'√Ñ')
    abort ();
  exit(0);
}
