// Modification timestamp: 2023-08-14 13:22:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20150611-1.c

#include <stdio.h>

int a, c, d;
short b;

int main(int argc, char *argv[]) {
  int e[1];
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int b = atoi(argv[1]);
  
  for (; b < 2; b++) {
    a = 0;
    if (b == 28378)
      a = e[b];
    if (!(d || b))
      for (; c;)
        ;
  }

  return 0;
}
