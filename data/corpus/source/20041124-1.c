// Modification timestamp: 2023-08-14 12:59:49
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20041124-1.c

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

struct s {
  _Complex unsigned short x;
};

struct s gs = { 100 + 200i };

struct s __attribute__((noinline)) foo(void) {
  return gs;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct s return_val = foo();
  
  if (return_val.x != gs.x) {
    abort();
  }
  
  exit(0);
}
