// Modification timestamp: 2023-08-14 14:44:16
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr19687.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

union U
{
  int i, j[4];
};

int main(int argc, char *argv[]) {
  union U t = {};
  int i;

  for (i = 0; i < 4; ++i)
    if (t.j[i] != 0)
      abort();

  return 0;
}
