// Modification timestamp: 2023-08-14 14:26:24
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/enum-2.c

#include <stdio.h>
#include <stdlib.h>

enum foo { FOO, BAR };

int main(int argc, char *argv[]) {
  int i;
  for (i = atoi(argv[1]); i >= atoi(argv[2]); --i)
    if (i == atoi(argv[3]))
      abort ();

  exit (0);
}
