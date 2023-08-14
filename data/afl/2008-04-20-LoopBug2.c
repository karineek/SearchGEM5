// Modification timestamp: 2023-08-14 17:23:36
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/2008-04-20-LoopBug2.c

#include <stdio.h>

extern int printf(const char*, ...);

void foo(unsigned int i, int array[4]) __attribute__((noinline));
void foo(unsigned int i, int array[4]) {
  unsigned int j = 3;
  do {
    array[j] = array[j - 1];
    j--;
  } while (j > i);
  printf("%d %d %d %d %d\n", i, array[0], array[1], array[2], array[3]);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int array[4], i;
  for (i = 0; i < 5; i++) {
    array[0] = atoi(argv[1]);
    array[1] = atoi(argv[2]);
    array[2] = atoi(argv[3]);
    array[3] = atoi(argv[4]);
    foo(i, array);
  }

  array[0] = atoi(argv[1]);
  array[1] = atoi(argv[2]);
  array[2] = atoi(argv[3]);
  array[3] = atoi(argv[4]);
  foo(0xffffffffU, array);

  return 0;
}
