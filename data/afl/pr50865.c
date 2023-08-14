// Modification timestamp: 2023-08-14 15:19:35
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr50865.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define INT64_MIN (-INT64_MAX - 1)

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long long l1 = atoll(argv[1]);
  long long l2 = -atoll(argv[2]);
  long long l3 = -atoll(argv[3]);

  if ((INT64_MIN % 1LL) != 0)
    abort();
  if ((INT64_MIN % l1) != 0)
    abort();
  if (l2 == -1) {
    if ((INT64_MIN % 1LL) != 0)
      abort();
  }
  else if ((INT64_MIN % -l2) != 0)
    abort();
  if ((INT64_MIN % -l3) != 0)
    abort();

  return 0;
}

Please note that the program now expects 3 command-line arguments: the values for `l1`, `l2`, and `l3`.