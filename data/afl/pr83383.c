// Modification timestamp: 2023-08-14 15:59:34
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr83383.c

#include <stdio.h>
#include <stdlib.h>

unsigned long long int a;
unsigned char b;
unsigned long long int c;
unsigned char d;
unsigned long long int e[2];
unsigned long long int f[2];
unsigned long long int g;

void foo(unsigned char *arg1, unsigned long long int *arg2, unsigned char *arg3, unsigned long long int *arg4, unsigned long long int *arg5) {
  *arg1 = ((signed char)(*arg2)) < (*arg3);
  *arg4 = (*arg5 ? arg4[0] : 0) - (f[1] * (*arg1) ? 1 : g);
}

int main(int argc, char *argv[]) {
  if (argc < 8) {
    printf("Usage: %s <a> <b> <c> <d> <e0> <f0> <f1> <g>\n", argv[0]);
    return 1;
  }

  a = strtoull(argv[1], NULL, 10);
  b = strtoul(argv[2], NULL, 10);
  c = strtoull(argv[3], NULL, 10);
  d = strtoul(argv[4], NULL, 10);
  e[0] = strtoull(argv[5], NULL, 10);
  f[0] = strtoull(argv[6], NULL, 10);
  f[1] = strtoull(argv[7], NULL, 10);
  g = strtoull(argv[8], NULL, 10);

  foo(&b, &a, &d, &c, &g);

  if (a != 1 || c != 3625445792498952485ULL) {
    __builtin_abort ();
  }

  return 0;
}
