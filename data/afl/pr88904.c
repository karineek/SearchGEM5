// Modification timestamp: 2023-08-14 16:04:09
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr88904.c

#include <stdio.h>
#include <stdlib.h>

volatile int v;

__attribute__((noipa)) void bar(const char *x, const char *y, int z) {
  if (!v)
    __builtin_abort();
  asm volatile("" : "+g"(x));
  asm volatile("" : "+g"(y));
  asm volatile("" : "+g"(z));
}

#define my_assert(e) ((e) ? (void)0 : bar(#e, __FILE__, __LINE__))

typedef struct {
  unsigned M1;
  unsigned M2 : 1;
  int : 0;
  unsigned M3 : 1;
} S;

S foo() {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  S result = {0, 0, 1};
  return result;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  S ret = foo();
  my_assert(ret.M2 == 0);
  my_assert(ret.M3 == 1);
  return 0;
}
