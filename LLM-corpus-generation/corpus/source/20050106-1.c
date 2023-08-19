// Modification timestamp: 2023-08-14 13:01:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20050106-1.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);

static inline unsigned short foo(unsigned int *p) {
  return *p;
};

unsigned int u;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int u = atoi(argv[1]);

  if ((foo(&u) & 0x8000) != 0)
    abort();
  return 0;
}
