// Modification timestamp: 2023-08-14 14:50:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr27364.c

#include <stdio.h>
#include <stdlib.h>

int f(unsigned number_of_digits_to_use)
{
  if (number_of_digits_to_use > 1294)
    return 0;
  return (number_of_digits_to_use * 3321928 / 1000000 + 1) / 16;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned number_of_digits_to_use = atoi(argv[1]);
  if (f(number_of_digits_to_use) != 2)
    __builtin_abort();
  exit(0);
}
