// Modification timestamp: 2023-08-14 13:48:19
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961223-1.c

#include <stdio.h>
#include <stdlib.h>

struct s {
  double d;
};

struct s sub(struct s s) {
  s.d += 1.0;
  return s;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct s t = { atof(argv[1]) };
  t = sub(t);
  if (t.d != atof(argv[1]) + 1.0)
    abort();
  exit(0);
}
