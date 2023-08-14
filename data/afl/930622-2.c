// Modification timestamp: 2023-08-14 13:34:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930622-2.c

#include <stdio.h>
#include <stdlib.h>

long double ll_to_ld(long long n) {
  return n;
}

long long ld_to_ll(long double n) {
  return n;
}

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  long long n;

  if (ll_to_ld(atoi(argv[1])) != 10.0)
    abort();

  if (ld_to_ll(10.0) != 10)
    abort();

  exit(0);
}
