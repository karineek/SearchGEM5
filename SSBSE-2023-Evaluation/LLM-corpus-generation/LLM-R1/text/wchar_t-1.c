// Modification timestamp: 2023-08-14 17:04:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/wchar_t-1.c
/* { dg-options "-finput-charset=utf-8" } */
typedef __WCHAR_TYPE__ wchar_t;
wchar_t x[] = L"√Ñ";
wchar_t y = L'√Ñ';
extern void abort (void);
extern void exit (int);

int main (void)
{
  if (sizeof (x) / sizeof (wchar_t) != 2)
    abort ();
  if (x[0] != L'√Ñ' || x[1] != L'\0')
    abort ();
  if (y != L'√Ñ')
    abort ();
  exit (0);
}
