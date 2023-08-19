// Modification timestamp: 2023-08-14 15:01:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr37931.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

int foo(int a, unsigned int b) {
  return (a | 1) & (b | 1);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int arg1 = atoi(argv[1]);
  unsigned int arg2 = strtoul(argv[2], NULL, 0);

  if (foo(arg1, arg2) != 7)
    abort();
  if (foo(arg3, arg4) != 0x81)
    abort();
  if (foo(arg5, arg6) != 5)
    abort();
  if (foo(arg7, arg8) != 5)
    abort();

  return 0;
}
