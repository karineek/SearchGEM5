// Modification timestamp: 2023-08-14 16:02:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr86231.c

#include <stdio.h>
#include <stdlib.h>

#define ONE ((void *) 1)
#define TWO ((void *) 2)

__attribute__((noipa)) int
foo (void *p, int x)
{
  if (p == ONE) return 0;
  if (!p)
    p = x ? TWO : ONE;
  return p == ONE ? 0 : 1;
}

int v[8];

int
main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s <value1> <value2>\n", argv[0]);
    return 1;
  }

  if (foo ((void *) 0, 0) != 0
      || foo ((void *) 0, 1) != 1
      || foo (argv[1], 0) != 0
      || foo (argv[1], 1) != 0
      || foo (argv[2], 0) != 1
      || foo (argv[2], 1) != 1
      || foo (&v[7], 0) != 1
      || foo (&v[7], 1) != 1)
    __builtin_abort ();
  return 0;
}
