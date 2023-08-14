// Modification timestamp: 2023-08-14 13:32:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/930126-1.c

#include <stdio.h>
#include <stdlib.h>

struct s {
  unsigned long long a: 8, b: 32;
};

struct s f(struct s x) {
  x.b = 0xcdef1234;
  return x;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct s i;
  i.a = atoi(argv[1]);
  i = f(i);
  
  if (i.a != 12 || i.b != 0xcdef1234) {
    abort();
  }

  exit(0);
}
