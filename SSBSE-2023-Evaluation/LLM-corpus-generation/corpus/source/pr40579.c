// Modification timestamp: 2023-08-14 15:06:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr40579.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
static char * __attribute__((noinline)) itos(int num) {
  return (char *)num;
}
static void __attribute__((noinline)) foo(int i, const char *x) {
  if (i >= 4)
    abort();
}
int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int i;

  for (i = 0; i < 4; ++i) {
    char *p;
    --x;
    p = itos(x);
    foo(i, p);
  }

  return 0;
}
