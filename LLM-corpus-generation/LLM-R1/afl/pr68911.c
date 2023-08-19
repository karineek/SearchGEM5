// Modification timestamp: 2023-08-14 15:48:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68911.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

char a;
int b, c;
short d;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned e = atoi(argv[1]);
  unsigned timeout = 0;

  for (; c < 2; c++) {
    int f = ~e / 7;
    if (f)
      a = e = ~(b && d);
    while (e < 94) {
      e++;
      if (++timeout > 100)
        goto die;
    }
  }
  return 0;
die:
  abort();
}
