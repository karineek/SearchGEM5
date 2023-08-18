// Modification timestamp: 2023-08-14 11:54:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20001130-2.c

#include <stdio.h>
#include <stdlib.h>

static int which_alternative = 3;

static const char *i960_output_ldconst(void);

static const char *output_25(void) {
  switch (which_alternative) {
    case 0:
      return "mov %1,%0";
    case 1:
      return i960_output_ldconst();
    case 2:
      return "ld %1,%0";
    case 3:
      return "st %1,%0";
  }
}

static const char *i960_output_ldconst(void) {
  return "foo";
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  const char *s = output_25();
  if (s[0] != 's') {
    abort();
  }
  exit(0);
}
