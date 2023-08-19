// Modification timestamp: 2023-08-14 15:14:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr46019.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned long long l = strtoull(argv[1], NULL, 0);
  int n;
  for (n = 0; n < 8; n++)
    if (l / (0x200000000ULL << n) != (0x200 >> n))
      abort();
  return 0;
}
