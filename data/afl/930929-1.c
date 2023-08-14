// Modification timestamp: 2023-08-14 13:36:07
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930929-1.c

#include <stdio.h>
#include <stdlib.h>

int sub1(int i) {
  return i - (5 - i);
}

int sub2(int i) {
  return i + (5 + i);
}

int sub3(int i) {
  return i - (5 + i);
}

int sub4(int i) {
  return i + (5 - i);
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  if (sub1(atoi(argv[1])) != 35)
    abort();
  if (sub2(atoi(argv[1])) != 45)
    abort();
  if (sub3(atoi(argv[1])) != -5)
    abort();
  if (sub4(atoi(argv[1])) != 5)
    abort();
  exit(0);
}
