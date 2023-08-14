// Modification timestamp: 2023-08-14 16:05:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr90025.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noipa)) void bar (char *p)
{
  int i;
  for (i = 0; i < 6; i++)
    if (p[i] != "foobar"[i])
      __builtin_abort ();
  for (; i < 32; i++)
    if (p[i] != '\0')
      __builtin_abort ();
}

__attribute__((noipa)) void foo (unsigned int x)
{
  char s[32] = { 'f', 'o', 'o', 'b', 'a', 'r', 0 };
  ((unsigned int *) s)[2] = __builtin_bswap32 (x);
  bar (s);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int x = atoi(argv[1]);

  foo (x);
  return 0;
}
