// Modification timestamp: 2023-08-14 12:06:48
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011115-1.c

#include <stdlib.h>

static inline int foo(void) {
#ifdef __OPTIMIZE__
  extern int undefined_reference;
  return undefined_reference;
#else
  return 0;
#endif
}

static inline int bar(void) {
  if (foo == foo)
    return 1;
  else
    return foo();
}

int main(int argc, char *argv[]) {
  exit(0);
}
