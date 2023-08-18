// Modification timestamp: 2023-08-14 13:35:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930719-1.c

#include <stdio.h>
#include <stdlib.h>

int f(int foo, int bar, int com) {
  unsigned align;
  if (foo)
    return 0;
  while (1) {
    switch (bar) {
      case 1:
        if (com != 0)
          return align;
        *(char *)0 = 0;
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    printf("Usage: %s <foo> <bar> <com>\n", argv[0]);
    return 1;
  }

  int foo = atoi(argv[1]);
  int bar = atoi(argv[2]);
  int com = atoi(argv[3]);

  f(foo, bar, com);
  exit(0);
}
