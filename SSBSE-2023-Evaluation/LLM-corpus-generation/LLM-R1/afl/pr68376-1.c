// Modification timestamp: 2023-08-14 15:46:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68376-1.c

#include <stdio.h>
#include <stdlib.h>

int a = 0, b = 0, c = 1;
signed char d;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  for (; a < atoi(argv[1]); a++)
    for (; b < atoi(argv[1]); b++) {
      signed char e = ~d;
      if (d < atoi(argv[1]))
        e = d;
      d = e;
      if (!c)
        abort();
    }

  if (d != 0)
    abort();

  return 0;
}
