// Modification timestamp: 2023-08-14 16:52:56
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/struct-ini-4.c

#include <stdio.h>
#include <stdlib.h>

struct s {
  int a[3];
  int c[3];
};

int main(int argc, char *argv[]) {
  struct s s = {
    .c = {1, 2, 3}
  };

  if (s.c[0] != 1)
    abort ();

  exit (0);
}
