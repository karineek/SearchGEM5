// Modification timestamp: 2023-08-14 13:45:40
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960326-1.c

#include <stdio.h>
#include <stdlib.h>

struct s
{
  int a;
  int b;
  short c;
  int d[3];
};

int main(int argc, char *argv[]) {
  struct s s = { .b = atoi(argv[1]), .d = {atoi(argv[2]), atoi(argv[3]), atoi(argv[4])} };

  if (s.b != 3)
    abort ();
  exit (0);
}
