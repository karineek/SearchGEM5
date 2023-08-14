// Modification timestamp: 2023-08-14 13:47:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960830-1.c

#include <stdlib.h>

#ifdef __i386__
void f(unsigned int *rp) {
  __asm__ ("mull %3" : "=a" (rp[0]), "=d" (rp[1]) : "%0" (7), "rm" (7));
}

int main() {
  unsigned int s[2];

  f(s);
  if (s[1] != 0 || s[0] != 49)
    abort();
  exit(0);
}
#else
int main() {
  exit(0);
}
#endif
