
// Modification timestamp: 2023-08-10 15:14:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/MallocBench/divrem.c

#include <stdio.h>

void test(unsigned X, unsigned Y) {
  printf("%u %u %u %u\n", X, Y, X / (8 << (Y&15)), X % (8 << (Y&15)));
}

int i;
int main(void) {
  long long l;

  for(i=10; i<139045193; i*=-3) {
    test(i, i^12345);
    i++;
  }

  return(0);
}
