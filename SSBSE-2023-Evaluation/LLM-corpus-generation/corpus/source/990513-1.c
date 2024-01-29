// Modification timestamp: 2023-08-14 13:55:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990513-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void foo(int *BM_tab, int j) {
  int *BM_tab_base;

  BM_tab_base = BM_tab;
  BM_tab += 0400;
  while (BM_tab_base != BM_tab) {
    *--BM_tab = j;
    *--BM_tab = j;
    *--BM_tab = j;
    *--BM_tab = j;
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int BM_tab[0400];
  memset(BM_tab, 0, sizeof(BM_tab));
  foo(BM_tab, atoi(argv[1]));
  if (BM_tab[0] != atoi(argv[2])) {
    abort();
  }
  return 0;
}
