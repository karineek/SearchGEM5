// Modification timestamp: 2023-08-14 14:51:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr29006.c
#include <stdlib.h>

#include <stdio.h>

struct __attribute__((__packed__)) s { char c; unsigned long long x; };
void __attribute__((__noinline__)) foo (struct s *s) { s->x = 0; }

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }
  
  struct s s = { atoi(argv[1]), ~0ULL };
  foo(&s);
  
  return s.x != 0;
}
