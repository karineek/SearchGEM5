// Modification timestamp: 2023-08-14 14:25:43
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/divmod-1.c

#include <stdio.h>
#include <stdlib.h>

signed char div1(signed char x) {
  return x / -1;
}

signed short div2(signed short x) {
  return x / -1;
}

signed char div3(signed char x, signed char y) {
  return x / y;
}

signed short div4(signed short x, signed short y) {
  return x / y;
}

signed char mod1(signed char x) {
  return x % -1;
}

signed short mod2(signed short x) {
  return x % -1;
}

signed char mod3(signed char x, signed char y) {
  return x % y;
}

signed short mod4(signed short x, signed short y) {
  return x % y;
}

signed long mod5(signed long x, signed long y) {
  return x % y;
}

unsigned long mod6(unsigned long x, unsigned long y) {
  return x % y;
}

int main(int argc, char *argv[]) {
  if (div1(atoi(argv[1])) != (1 << 7))
    abort();
  if (div2(atoi(argv[2])) != (1 << 15))
    abort();
  if (div3(atoi(argv[3]), atoi(argv[4])) != (1 << 7))
    abort();
  if (div4(atoi(argv[5]), atoi(argv[6])) != (1 << 15))
    abort();
  if (mod1(atoi(argv[7])) != 0)
    abort();
  if (mod2(atoi(argv[8])) != 0)
    abort();
  if (mod3(atoi(argv[9]), atoi(argv[10])) != 0)
    abort();
  if (mod4(atoi(argv[11]), atoi(argv[12])) != 0)
    abort();
  if (mod5(atol(argv[13]), atol(argv[14])) != 0)
    abort();
  if (mod6(atol(argv[15]), atol(argv[16])) != 0)
    abort();

  exit(0);
}
