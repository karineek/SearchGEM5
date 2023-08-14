// Modification timestamp: 2023-08-14 15:08:44
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42142.c

#include <stdio.h>
#include <stdlib.h>

int sort(int L) {
  int end[2] = {atoi(argv[1]), atoi(argv[2])}, i = 0, R;
  while (i < 2) {
    R = end[i];
    if (L < R) {
      end[i + 1] = atoi(argv[3]);
      end[i] = atoi(argv[4]);
      ++i;
    } else
      break;
  }
  return i;
}

extern void abort(void);

int main(int argc, char *argv[]) {
  if (sort(atoi(argv[5])) != atoi(argv[6]))
    abort();
  return 0;
}

Note: The command line arguments `argv[1]` to `argv[6]` should be passed accordingly.