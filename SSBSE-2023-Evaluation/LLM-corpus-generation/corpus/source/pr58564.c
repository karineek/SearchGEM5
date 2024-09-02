// Modification timestamp: 2023-08-14 15:30:57
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58564.c

/* PR middle-end/58564 */

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

int a, b;
short *c, **d = &c;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int arg = atoi(argv[1]);
  
  b = (0, 0 > ((&c == d) & (1 && (a ^ 1)))) | arg;
  
  if (b != 0)
    abort ();

  return 0;
}
