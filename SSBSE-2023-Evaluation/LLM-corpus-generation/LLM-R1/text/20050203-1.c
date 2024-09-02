// Modification timestamp: 2023-08-14 13:02:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050203-1.c
/* Reduced testcase extracted from Samba source code.  */

#include <stdlib.h>

static void __attribute__((__noinline__))
     foo (unsigned char *p) {
  *p = 0x81;
}

static void __attribute__((__noinline__))
     bar (int x) {
  asm ("");
}

int main() {
  unsigned char b;

  foo(&b);
  if (b & 0x80)
    {
      bar (b & 0x7f);
      exit (0);
    }
  else
    {
      bar (b & 1);
      abort ();
    }
}
