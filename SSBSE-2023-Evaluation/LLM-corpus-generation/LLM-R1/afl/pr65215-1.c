// Modification timestamp: 2023-08-14 15:42:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr65215-1.c

#include <stdio.h>
#include <stdlib.h>

static inline unsigned int foo(unsigned int x) {
  return (x >> 24) | ((x >> 8) & 0xff00) | ((x << 8) & 0xff0000) | (x << 24);
}

__attribute__((noinline, noclone)) unsigned int bar(unsigned long long *x) {
  return foo(*x);
}

int main(int argc, char *argv[]) {
  if (__CHAR_BIT__ != 8 || sizeof(unsigned int) != 4 || sizeof(unsigned long long) != 8) {
    printf("Architecture not supported\n");
    return 1;
  }
  
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  unsigned long long l = foo(0xdeadbeefU) | 0xfeedbea800000000ULL;
  unsigned int result = bar(&l);
  
  printf("Result: 0x%08x\n", result);
  
  unsigned int expected = atoi(argv[1]);
  if (result != expected) {
    printf("Expected: 0x%08x\n", expected);
    return 1;
  }
  
  return 0;
}

Note: I added error handling for unsupported architectures and command line argument parsing for the expected result.