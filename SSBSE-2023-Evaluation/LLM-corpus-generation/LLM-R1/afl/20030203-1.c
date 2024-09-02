// Modification timestamp: 2023-08-14 12:42:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030203-1.c

#include <stdio.h>
#include <stdlib.h>

void f(int);

int do_layer3(int single) {
  if (single >= 0) /* stream is stereo, but force to mono */
    int stereo1 = 1;
  else
    int stereo1 = 2;
  f(single);

  return stereo1;
}

extern void abort();

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int single = atoi(argv[1]);

  if (do_layer3(single) != 2)
    abort();

  return 0;
}

void f(int i) {}
