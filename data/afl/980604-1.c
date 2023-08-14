// Modification timestamp: 2023-08-14 13:50:00
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980604-1.c

#include <stdio.h>
#include <stdlib.h>

int a = 1;
int b = -1;

int c = 1;
int d = 0;

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <arg1> <arg2>\n", argv[0]);
    return 1;
  }

  double e;
  double f;
  double g;

  f = atof(argv[1]);
  g = atof(argv[2]);
  e = (a < b) ? f : g;
  if (e)
    abort ();
  exit(0);
}
