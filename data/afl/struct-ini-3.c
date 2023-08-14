// Modification timestamp: 2023-08-14 16:52:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/struct-ini-3.c

#include <stdio.h>
#include <stdlib.h>

struct {
  unsigned int f1:1, f2:1, f3:3, f4:3, f5:2, f6:1, f7:1;
} result;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  result.f1 = atoi(argv[1]);
  result.f2 = atoi(argv[2]);
  result.f3 = atoi(argv[3]);
  result.f4 = atoi(argv[4]);
  result.f5 = atoi(argv[5]);
  result.f6 = atoi(argv[6]);
  result.f7 = atoi(argv[7]);

  if ((result.f3 & ~7) != 0 || (result.f4 & ~7) != 0)
    abort ();
  exit(0);
}

Note: Since the field widths of the bitfields are fixed, the corresponding command-line arguments are assigned to each bitfield member in the main function.