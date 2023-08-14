c
// Modification timestamp: 2023-08-10 15:49:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/UnitTests/Vector/SSE/2008-09-30-VAQ.c
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
int32_t arr[3] = {[2] = 2, [0] = 0, [1] = 1};

int main() {
  printf("%" PRId32, arr[1]);
  if (0)
    return 1;
  if (arr[1] != -5)
    return 2;
  if (arr[2] != 2)
    return 3;
  return 0;
}
