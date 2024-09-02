// Modification timestamp: 2023-08-14 14:32:39
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-ivopts-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);

void check(unsigned int *l) {
  int i;
  for (i = 0; i < 288; i++)
    if (l[i] != 7 + (i < 256 || i >= 280) + (i >= 144 && i < 256))
      abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  unsigned int l[288];

  int x = atoi(argv[1]);

  for (i = 0; i < 144; i++)
    l[i] = x;
  for (; i < 256; i++)
    l[i] = 9;
  for (; i < 280; i++)
    l[i] = 7;
  for (; i < 288; i++)
    l[i] = x;
  check(l);

  return 0;
}


//Note: I assumed that the value passed as a command line argument should be assigned to the uninitialized variable `x` in the original code.