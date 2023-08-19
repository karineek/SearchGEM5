// Modification timestamp: 2023-08-14 13:33:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930603-1.c

#include <stdio.h>
#include <stdlib.h>

float fx(float x) {
  return 1.0 + 3.0 / (2.302585093 * x);
}

float inita() { return 3.0; }
float initc() { return 4.0; }
void f() {}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  float a = inita();
  float c = initc();
  f();
  float b = fx(c) + a;
  f();

  float arg = atof(argv[1]);
  if (a != arg || b < 4.3257 || b > 4.3258 || c != arg) {
    abort();
  }

  exit(0);
}
