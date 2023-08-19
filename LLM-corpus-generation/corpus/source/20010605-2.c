// Modification timestamp: 2023-08-14 11:59:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20010605-2.c

#include <stdio.h>
#include <stdlib.h>

void foo (__complex__ double x);
void bar (__complex__ float x);
void baz (__complex__ long double x);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;

  __real__ x = atof(argv[1]);
  __imag__ x = atof(argv[2]);
  foo(x);

  __real__ y = atof(argv[3]);
  __imag__ y = atof(argv[4]);
  bar(y);

  __real__ z = atof(argv[5]);
  __imag__ z = atof(argv[6]);
  baz(z);

  exit(0);
}

void foo (__complex__ double x) {
  if (__real__ x != 1.0 || __imag__ x != 2.0)
    abort();
}

void bar (__complex__ float x) {
  if (__real__ x != 3.0f || __imag__ x != 4.0f)
    abort();
}

void baz (__complex__ long double x) {
  if (__real__ x != 5.0L || __imag__ x != 6.0L)
    abort();
}


//Please note that this assumes the command-line arguments are provided in the correct order as `./program arg1 arg2 arg3 arg4 arg5 arg6`.