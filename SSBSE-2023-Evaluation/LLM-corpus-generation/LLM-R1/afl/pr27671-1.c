// Modification timestamp: 2023-08-14 14:50:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr27671-1.c

#include <stdio.h>
#include <stdlib.h>

void abort (void) __attribute__ ((noreturn));
void exit (int) __attribute__ ((noreturn));

static int __attribute__((noinline))
foo (int a, int b)
{
  int c = a ^ b;
  if (c == a)
    abort ();
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <a> <b>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);

  foo(a, b);
  exit(0);
}
