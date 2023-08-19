// Modification timestamp: 2023-08-14 13:55:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/990604-1.c


#include <stdio.h>
#include <stdlib.h>

int b;

void f () {
  int i = 0;
  if (b == 0)
    do {
      b = i;
      i++;
    } while (i < 10);
}

int main (int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = 0;
  void (*p)() = &f;
  p();
  if (b != y) {
    abort();
  }
  
  return 0;
}
