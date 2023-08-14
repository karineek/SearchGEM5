// Modification timestamp: 2023-08-14 15:51:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr71550.c

#include <stdio.h>
#include <stdlib.h>

extern void exit(int);

int a = 3, b, c, f, g, h;
unsigned d;
char *e;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = 0;
  unsigned z = atoi(argv[2]);
  char *w = argv[3];

  for (; x; x--) {
    int i;
    if (y && i)
      printf("%d%d", c, f);
    i = 0;
    for (; i < 2; i++)
      if (g)
        for (; z < 10; z++)
          b = *w;
    i = 0;
    for (; i < 1; i++)
      ;
  }
  exit(0);
}

