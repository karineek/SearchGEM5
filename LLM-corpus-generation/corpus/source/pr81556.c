// Modification timestamp: 2023-08-14 15:56:46
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr81556.c

#include <stdio.h>
#include <stdlib.h>

unsigned long long int b;
unsigned long long int c;
unsigned long long int d;
unsigned long long int f;
unsigned long long int g;
unsigned long long int h;
unsigned long long int e;

__attribute__((noinline, noclone)) void foo(unsigned long long int arg_d, unsigned long long int arg_f, unsigned long long int arg_g, unsigned long long int arg_h, unsigned long long int arg_e, unsigned long long int arg_b, unsigned long long int arg_c) {
  _Bool a = arg_d > 1;
  arg_g = arg_f % ((arg_d > 1) << 9);
  arg_h = a & (arg_e & (a & arg_b & arg_c));
}

int main(int argc, char *argv[]) {
  if (argc != 8) {
    printf("Usage: %s <arg_d> <arg_f> <arg_g> <arg_h> <arg_e> <arg_b> <arg_c>\n", argv[0]);
    return 1;
  }

  unsigned long long int arg_d = strtoull(argv[1], NULL, 0);
  unsigned long long int arg_f = strtoull(argv[2], NULL, 0);
  unsigned long long int arg_g = strtoull(argv[3], NULL, 0);
  unsigned long long int arg_h = strtoull(argv[4], NULL, 0);
  unsigned long long int arg_e = strtoull(argv[5], NULL, 0);
  unsigned long long int arg_b = strtoull(argv[6], NULL, 0);
  unsigned long long int arg_c = strtoull(argv[7], NULL, 0);

  foo(arg_d, arg_f, arg_g, arg_h, arg_e, arg_b, arg_c);

  if (arg_g != 1 || arg_h != 0) {
    __builtin_abort();
  }
  
  return 0;
}
