
// Modification timestamp: 2023-08-10 14:43:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/MultiSource/Benchmarks/BitBench/divtest.c

#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

extern int printf(const char *, ...);

void testL(int64_t Arg) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int64_t Arg = atoll(argv[1]);
  printf("%d\n", (int) (Arg / ((int64_t)1 << 4)));
  printf("%d\n", (int) (Arg / ((int64_t)1 << 46)));
}

void test(int Arg) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int Arg = atoi(argv[1]);
  printf("%d\n", Arg / (1 << 0));
  printf("%d\n", Arg / (1 << 4));
  printf("%d\n", Arg / (1 << 18));
  printf("%d\n", Arg / (1 << 30));
}

int main(int argc, char *argv[]) {
  int B20;
  int64_t B53;
  
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  B20 = atoi(argv[1]) + 32;
  B53 = atoll(argv[1]) + 64;

  test(B20);
  test(B20 + 1);

  testL(B53);
  testL(B53 + 1);

  return 0;
}
