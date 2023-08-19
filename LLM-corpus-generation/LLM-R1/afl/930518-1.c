// Modification timestamp: 2023-08-14 13:33:28
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930518-1.c

#include <stdio.h>
#include <stdlib.h>

int bar = 0;

void f(int *p) {
  int foo = 2;

  while (foo > bar) {
    foo -= bar;
    *p++ = foo;
    bar = 1;
  }
}

int main(int argc, char *argv[]) {
  int tab[2];
  tab[0] = tab[1] = 0;
  f(tab);
  if (tab[0] != 2 || tab[1] != 1)
    abort();
  exit(0);
}
