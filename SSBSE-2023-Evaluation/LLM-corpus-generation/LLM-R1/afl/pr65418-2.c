// Modification timestamp: 2023-08-14 15:44:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr65418-2.c

#include <stdio.h>
#include <stdlib.h>

__attribute__((noinline, noclone)) int
foo(int x, int* values, int size)
{
  for (int i = 0; i < size; i++) {
    if (x == values[i])
      return 1;
  }
  return 0;
}

int main(int argc, char* argv[])
{
  if (argc < 7) {
    printf("Usage: %s <value> <value> <value> <value> <value> <value>\n", argv[0]);
    return 1;
  }

  int values[5];

  for (int i = 0; i < 5; i++) {
    values[i] = atoi(argv[i + 1]);
  }

  volatile int i;
  for (i = -230; i < -200; i++) {
    if (foo(i, values, 5) != (i == values[0] || i == values[1] || i == values[2] || i == values[3] || i == values[4])) {
      __builtin_abort();
    }
  }

  return 0;
}
