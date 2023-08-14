// Modification timestamp: 2023-08-14 12:16:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020503-1.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);
static char *inttostr(long i, char buf[128]);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char buf[128], *p;

  int i = atoi(argv[1]);

  p = inttostr(i, buf);
  if (*p != '-') {
    abort();
  }
  return 0;
}

static char *inttostr(long i, char buf[128]) {
  unsigned long ui = i;
  char *p = buf + 127;
  *p = '\0';
  if (i < 0)
    ui = -ui;
  do
    *--p = '0' + ui % 10;
  while ((ui /= 10) != 0);
  if (i < 0)
    *--p = '-';
  return p;
}
