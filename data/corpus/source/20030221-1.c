// Modification timestamp: 2023-08-14 12:43:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030221-1.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char buf[16] = {0};
  strncpy(buf, argv[1], sizeof(buf) - 1);

  char *p = buf;
  *p++ = (char)strlen(buf);

  if ((buf[0] != 10) || (p - buf != 1))
    abort();

  return 0;
}
