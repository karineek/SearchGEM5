// Modification timestamp: 2023-08-14 17:04:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/widechar-2.c
#include <stddef.h>

const wchar_t ws[] = L"foo";

int
main (void)
{
  if (ws[0] != L'f' || ws[1] != L'o' || ws[2] != L'o' || ws[3] != L'\0')
    abort();
  exit(0);
}
