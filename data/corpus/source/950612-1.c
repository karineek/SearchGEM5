// Modification timestamp: 2023-08-14 13:42:27
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950612-1.c

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int f1(int diff) {
  return (unsigned int)(diff < 0 ? -diff : diff);
}

unsigned int f2(unsigned int diff) {
  return (unsigned int)((signed int)diff < 0 ? -diff : diff);
}

unsigned long long f3(long long diff) {
  return (unsigned long long)(diff < 0 ? -diff : diff);
}

unsigned long long f4(unsigned long long diff) {
  return (unsigned long long)((signed long long)diff < 0 ? -diff : diff);
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  int i;
  for (i = 0; i <= 10; i++) {
    if (f1(i) != i)
      abort();
    if (f1(-i) != i)
      abort();
    if (f2(i) != i)
      abort();
    if (f2(-i) != i)
      abort();
    if (f3((long long)i) != i)
      abort();
    if (f3((long long)-i) != i)
      abort();
    if (f4((long long)i) != i)
      abort();
    if (f4((long long)-i) != i)
      abort();
  }
  exit(0);
}
