// Modification timestamp: 2023-08-14 13:02:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050203-1.c
#include <stdio.h>

#include <stdlib.h>

static void __attribute__((__noinline__))
     foo (unsigned char *p) {
  *p = 0x81;
}

static void __attribute__((__noinline__))
     bar (int x) {
  asm ("");
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned char b = atoi(argv[1]);

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
