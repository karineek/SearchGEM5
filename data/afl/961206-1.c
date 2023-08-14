// Modification timestamp: 2023-08-14 13:48:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961206-1.c

#include <stdio.h>
#include <stdlib.h>

int sub1(unsigned long long i) {
  if (i < strtoull(argv[1], NULL, 0x10))
    return 1;
  else
    return 0;
}

int sub2(unsigned long long i) {
  if (i <= strtoull(argv[1], NULL, 0x10))
    return 1;
  else
    return 0;
}

int sub3(unsigned long long i) {
  if (i >= strtoull(argv[1], NULL, 0x10))
    return 0;
  else
    return 1;
}

int sub4(unsigned long long i) {
  if (i > strtoull(argv[1], NULL, 0x10))
    return 0;
  else
    return 1;
}

int main(int argc, char *argv[]) {
  if (sub1(strtoull(argv[1], NULL, 0x10)))
    abort();

  if (sub2(strtoull(argv[1], NULL, 0x10)))
    abort();

  if (sub3(strtoull(argv[1], NULL, 0x10)))
    abort();

  if (sub4(strtoull(argv[1], NULL, 0x10)))
    abort();

  exit(0);
}

Note: The `strtoull` function is used to convert the hexadecimal value from the command-line argument to an `unsigned long long` integer.