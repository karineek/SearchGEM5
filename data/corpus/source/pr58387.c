// Modification timestamp: 2023-08-14 15:30:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr58387.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int a;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  a = atoi(argv[1]);

  int b = a == 0 ? 0 : -a;
  if (b < 1)
    abort ();
  return 0;
}
