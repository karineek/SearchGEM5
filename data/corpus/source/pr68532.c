// Modification timestamp: 2023-08-14 15:47:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68532.c

#include <stdio.h>
#include <stdlib.h>

#define SIZE 128
unsigned short _Alignas(16) in[SIZE];

__attribute__((noinline)) int test(unsigned short sum, unsigned short *in, int x) {
  for (int j = 0; j < SIZE; j += 8)
    sum += in[j] * x;
  return sum;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  
  for (int i = 0; i < SIZE; i++)
    in[i] = i;
  
  if (test(0, in, x) != 960)
    __builtin_abort();

  return 0;
}
