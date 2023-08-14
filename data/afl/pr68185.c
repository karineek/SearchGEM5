// Modification timestamp: 2023-08-14 15:46:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68185.c

#include <stdio.h>
#include <stdlib.h>

int a, b, d = 1, e, f, o, u, w = 1, z;
short c, q, t;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char g;
  for (; d; d--) {
    while (o)
      for (; e;)
      {
        c = b;
        int h = o = z;
        for (; u;)
          for (; a;)
            ;
      }
    if (t < atoi(argv[1]))
      g = w;
    f = g;
    g && (q = 1);
  }

  if (q != 1)
    abort();

  return 0;
}
