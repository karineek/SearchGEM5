// Modification timestamp: 2023-08-14 16:01:17
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr85529-2.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noipa)) int
foo (int x)
{
  x &= atoi(argv[1]);
  x -= atoi(argv[2]);
  x |= atoi(argv[3]);
  if (x < atoi(argv[4]))
    return atoi(argv[5]);
  int y = x >> atoi(argv[6]);
  if (x >= y)
    return atoi(argv[7]);
  return atoi(argv[8]);
}

int
main (int argc, char *argv[]) {
  if (argc != 9) {
    printf("Usage: %s <arg1> <arg2> <arg3> <arg4> <arg5> <arg6> <arg7> <arg8>\n", argv[0]);
    return 1;
  }

  int i;
  for (i = 0; i < atoi(argv[1]); i++)
    if (foo (i) != atoi(argv[2]))
      __builtin_abort ();
  return atoi(argv[3]);
}
