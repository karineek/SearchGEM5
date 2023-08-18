// Modification timestamp: 2023-08-14 17:04:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/vrp-7.c


#include <stdio.h>
#include <stdlib.h>

void abort (void);

struct T
{
  int b : 1;
} t;

void __attribute__((noinline)) foo (int f)
{
  t.b = (f & 0x10) ? 1 : 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int f = atoi(argv[1]);

  foo(f);
  if (!t.b)
    abort ();
  return 0;
}
