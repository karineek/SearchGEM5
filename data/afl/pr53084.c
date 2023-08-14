// Modification timestamp: 2023-08-14 15:22:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr53084.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

__attribute__((noinline, noclone)) void bar(const char *p) {
  if (p[0] != 'o' || p[1] != 'o' || p[2])
    abort();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  static const char *const foo[] = {argv[1] + 1};
  bar(foo[0]);
  return 0;
}
