// Modification timestamp: 2023-08-14 14:09:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/builtin-constant.c

#include <stdio.h>
#include <stdlib.h>

#define btest(x) __builtin_constant_p(x) ? "1" : "0"

#ifdef __OPTIMIZE__
void foo(char *i) {
  if (*i == '0')
    abort();
}
#else
void foo(char *i) {
}
#endif

int main(int argc, char *argv[]) {
  int size = sizeof(int);
  foo(argv[1]);
  foo(argv[2]);
  exit(0);
}
