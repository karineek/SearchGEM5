// Modification timestamp: 2023-08-14 15:54:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr79327.c

#include <stdio.h>
#include <stdlib.h>

volatile int a;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  char buf[64];
  if (__builtin_sprintf(buf, "%#hho", atoi(argv[1])) != 1)
    __builtin_abort();
  if (__builtin_sprintf(buf, "%#hhx", atoi(argv[1])) != 1)
    __builtin_abort();
  a = 1;
  if (__builtin_sprintf(buf, "%#hho", a) != 2)
    __builtin_abort();
  if (__builtin_sprintf(buf, "%#hhx", a) != 3)
    __builtin_abort();
  a = 127;
  if (__builtin_sprintf(buf, "%#hho", a) != 4)
    __builtin_abort();
  if (__builtin_sprintf(buf, "%#hhx", a) != 4)
    __builtin_abort();
  return 0;
}
