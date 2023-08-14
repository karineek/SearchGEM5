// Modification timestamp: 2023-08-14 13:48:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/970214-2.c
#define m(L) (L'1' + (L))
main ()
{
  exit (m (0) != L'1');
}
