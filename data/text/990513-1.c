// Modification timestamp: 2023-08-14 13:55:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990513-1.c
#include <string.h>

void foo (int *BM_tab, int j)
{
  int *BM_tab_base;

  BM_tab_base = BM_tab;
  BM_tab += 0400;
  while (BM_tab_base != BM_tab)
    {
      *--BM_tab = j;
      *--BM_tab = j;
      *--BM_tab = j;
      *--BM_tab = j;
    }
}

int main ()
{
  int BM_tab[0400];
  memset (BM_tab, 0, sizeof (BM_tab));
  foo (BM_tab, 6);
  if (BM_tab[0] != 6)
    abort ();
  return 0;
}
