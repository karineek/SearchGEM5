// Modification timestamp: 2023-08-14 13:49:23
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980526-1.c

#include <stdio.h>
#include <stdlib.h>

int expect_do1 = 1, expect_do2 = 2;

static int doit(int x){
  __label__ lbl1;
  __label__ lbl2;
  static int jtab_init = 0;
  static void *jtab[2];

  if(!jtab_init) {
    jtab[0] = &&lbl1;
    jtab[1] = &&lbl2;
    jtab_init = 1;
  }
  goto *jtab[x];
lbl1:
  return 1;
lbl2:
  return 2;
}

static void do1(void) {
  if (doit(0) != expect_do1)
    abort ();
}

static void do2(void){
  if (doit(1) != expect_do2)
    abort ();
}

int main(int argc, char *argv[]) {
  exit(0);
}

