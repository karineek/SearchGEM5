// Modification timestamp: 2023-08-14 12:46:22
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20030626-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int sprintf(char *, const char *, ...);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char buf[10];
  int l = sprintf(buf, "%s\0%s", argv[1], argv[2]);
  if (l != 3)
    abort();

  return 0;
}
