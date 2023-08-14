// Modification timestamp: 2023-08-14 13:42:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/950607-1.c

#include <stdlib.h>

int main(int argc, char *argv[]) {
  struct { long status; } h;

  h.status = 0;
  if (((h.status & atoi(argv[1])) == atoi(argv[2])) && ((h.status & atoi(argv[3])) == atoi(argv[4])))
    abort ();
  exit(0);
}
