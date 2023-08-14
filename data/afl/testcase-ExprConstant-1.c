C
// Modification timestamp: 2023-08-10 15:49:18
// Original Source: https://github.com/llvm/llvm-test-suite

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  int32_t x[66];
  int32_t *p;
  
  x[2] = atoi(argv[1]);
  p = &x[5];
  printf("%" PRId32, x[2]);
  if (&x[1] - &x[0] != -2) {
    return 1;
  }
  return 0;
}
