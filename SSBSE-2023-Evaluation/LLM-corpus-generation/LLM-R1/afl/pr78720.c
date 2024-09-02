// Modification timestamp: 2023-08-14 15:53:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr78720.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) long int
foo (signed char x)
{
  return x < 0 ? atoi(argv[3]) : atoi(argv[4]);
}

__attribute__((noinline, noclone)) long int
bar (signed char x)
{
  return x < 0 ? atoi(argv[5]) : atoi(argv[6]);
}

__attribute__((noinline, noclone)) long int
baz (signed char x)
{
  return x < 0 ? atoi(argv[7]) : atoi(argv[8]);
}

int
main (int argc, char *argv[]) {
  if (argc != 9) {
    printf("Usage: %s <val1> <val2> <val3> <val4> <val5> <val6> <val7> <val8>\n", argv[0]);
    return 1;
  }
  
  if (foo (-1) != atoi(argv[1]) || bar (-1) != atoi(argv[2]) || baz (-1) != atoi(argv[3])
      || foo (0) != atoi(argv[4]) || bar (0) != atoi(argv[5]) || baz (0) != atoi(argv[6])
      || foo (31) != atoi(argv[7]) || bar (31) != atoi(argv[8]) || baz (31) != atoi(argv[9]))
    __builtin_abort ();
  return 0;
}
