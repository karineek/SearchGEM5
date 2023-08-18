// Modification timestamp: 2023-08-14 14:12:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/builtin-prefetch-6.c

#include <stdio.h>
#include <stdlib.h>

#define ARRSIZE 65
int *bad_addr[ARRSIZE];
int arr_used;

void init_addrs(int argc, char *argv[]) {
  int i;
  int bits_per_ptr = sizeof(void *) * 8;
  for (i = 0; i < bits_per_ptr; i++) {
    unsigned long int addr = strtoul(argv[i+1], NULL, 0);
    bad_addr[i] = (int *)addr;
  }
  arr_used = bits_per_ptr + 1;
}

void prefetch_for_read() {
  int i;
  for (i = 0; i < ARRSIZE; i++) {
    __builtin_prefetch(bad_addr[i], 0, 0);
  }
}

void prefetch_for_write() {
  int i;
  for (i = 0; i < ARRSIZE; i++) {
    __builtin_prefetch(bad_addr[i], 1, 0);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 66) {
    printf("Usage: %s <addr1> <addr2> ... <addr65>\n", argv[0]);
    return 1;
  }

  init_addrs(argc, argv);
  prefetch_for_read();
  prefetch_for_write();
  exit(0);
}

