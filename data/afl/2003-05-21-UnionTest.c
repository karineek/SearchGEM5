
// Modification timestamp: 2023-08-10 15:53:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Benchmarks/Misc/2003-05-21-UnionTest.c

#include <stdio.h>
#include <stdlib.h>

int __signbit (double __x) {
  union { double __d; int __i[3]; } __u = { __d: __x };
  return __u.__i[1] < 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  double x = atof(argv[1]);
  printf("%d %d\n", __signbit(-1), __signbit(x));
  return 0;
}
