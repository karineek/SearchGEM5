// Modification timestamp: 2023-08-14 15:15:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr47155.c

#include <stdio.h>
#include <stdlib.h>

unsigned int a;
static signed char b = -127;
int c = 1;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int value = atoi(argv[1]);

  a = b <= (unsigned char)(-6 * value);
  if (!a)
    __builtin_abort();
  return 0;
}
