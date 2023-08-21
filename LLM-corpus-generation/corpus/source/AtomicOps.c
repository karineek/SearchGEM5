// Modification timestamp: 2023-08-14 17:27:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/AtomicOps.c

#include <stdio.h>

int foo(volatile *mem, int val, int c) {
  int oldval = __sync_fetch_and_add(mem, val);
  return oldval + c;
}

volatile int x = 0;
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  long long test = 0;
  int x = atoi(argv[1]);
  int y = foo(&x, atoi(argv[2]), atoi(argv[3]));
  printf("%d, %d\n", y, x);
  y = __sync_val_compare_and_swap(&x, atoi(argv[4]), atoi(argv[5]));
  printf("%d, %d\n", y, x);
  y = __sync_lock_test_and_set(&x, atoi(argv[6]));
  printf("%d, %d\n", y, x);

  for (i = 0; i < 5; i++) {
    __sync_add_and_fetch(&test, atoi(argv[7]));
    printf("test = %d\n", (int)test);
  }

  for (i = 0; i < 5; i++) {
    __sync_fetch_and_sub(&test, atoi(argv[8]));
    printf("test = %d\n", (int)test);
  }

  return 0;
}
