
// Modification timestamp: 2023-08-10 15:38:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/AtomicOps.c

#include <stdio.h>
#include <stdlib.h>

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

  long long test = 0;
  int i;
  int y = foo(&x, atoi(argv[1]), atoi(argv[2]));
  printf("%d, %d\n", y, x);
  y = __sync_val_compare_and_swap(&x, atoi(argv[3]), atoi(argv[4]));
  printf("%d, %d\n", y, x);
  y = __sync_lock_test_and_set(&x, atoi(argv[5]));
  printf("%d, %d\n", y, x);

  for (i = 0; i < 5; i++) {
    __sync_add_and_fetch(&test, atoi(argv[6]));
    printf("test = %d\n", (int)test);
  }

  for (i = 0; i < 5; i++) {
    __sync_fetch_and_sub(&test, atoi(argv[7]));
    printf("test = %d\n", (int)test);
  }

  return 0;
}
