// Modification timestamp: 2023-08-14 15:40:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr63659.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b, c, *d = &b, g, h, i;
  unsigned char e;
  char f;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  a = atoi(argv[1]);

  while (a)
  {
    for (a = 0; a; a++)
      for (; c; c++);

    if (i)
      break;
  }

  char j = c, k = -1, l;
  l = g = j >> h;
  f = l == 0 ? k : k % l;
  e = 0 ? 0 : f;
  *d = e;

  if (b != 255)
    __builtin_abort ();

  return 0;
}
