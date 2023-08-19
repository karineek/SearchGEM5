// Modification timestamp: 2023-08-14 16:06:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pushpop_macro.c

#include <stdio.h>
#include <stdlib.h>

extern void abort ();

#define ARG_2 2
#pragma push_macro("ARG_2")
#undef ARG_2
#define ARG_2 1
#pragma pop_macro("ARG_2")

int main (int argc, char *argv[]) {
  if (ARG_2 != 2)
    abort ();
  return 0;
}

