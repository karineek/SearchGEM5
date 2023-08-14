// Modification timestamp: 2023-08-14 17:04:04
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/vrp-3.c

#include <stdio.h>
#include <stdlib.h>

int f(int a) {
  if (a < atoi(argv[1])) {
    if (a > atoi(argv[2])) {
      a = a > 0 ? a : -a;
      if (a == atoi(argv[3]))
        return 0;
      return 1;
    }
  }
  return 1;
}

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("Usage: %s <value1> <value2> <value3> <value4>\n", argv[0]);
    return 1;
  }

  if (f(atoi(argv[4])))
    abort();
  exit(0);
}
