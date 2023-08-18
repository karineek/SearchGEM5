// Modification timestamp: 2023-08-14 14:50:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr27260.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void abort(void);
extern void *memset(void *, int, size_t);

char buf[65];

void foo(int x, char *buf) { // Added buf as a parameter
  memset(buf, x != 2 ? 1 : 0, 64);
}

int main(int argc, char *argv[]) { // Added arguments to main
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i;
  buf[64] = atoi(argv[1]); // Use atoi to convert argument to integer
  for (i = 0; i < 64; i++)
    if (buf[i] != 0)
      abort();
  foo(0, buf);
  for (i = 0; i < 64; i++)
    if (buf[i] != 1)
      abort();
  foo(2, buf);
  for (i = 0; i < 64; i++)
    if (buf[i] != 0)
      abort();
  if (buf[64] != 2)
    abort();
  return 0;
}

