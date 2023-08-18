// Modification timestamp: 2023-08-14 14:59:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr37125.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

static inline unsigned int mod_rhs(int rhs) {
  if (rhs == 0) return 1;
  return rhs;
}

void func_44(unsigned int p_45);
void func_44(unsigned int p_45) {
  if (!((p_45 * -9) % mod_rhs(-9))) {
    abort();
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int p_45 = atoi(argv[1]);
  func_44(p_45);
  return 0;
}

