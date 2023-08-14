// Modification timestamp: 2023-08-14 14:12:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/builtin-prefetch-5.c

#include <stdio.h>
#include <stdlib.h>

struct S {
  short a;
  short b;
  char c[8];
} s;

char arr[100];
char *ptr = arr;
int idx = 3;

void arg_ptr(char *p) {
  __builtin_prefetch(p, 0, 0);
}

void arg_idx(char *p, int i) {
  __builtin_prefetch(&p[i], 0, 0);
}

void glob_ptr(void) {
  __builtin_prefetch(ptr, 0, 0);
}

void glob_idx(void) {
  __builtin_prefetch(&ptr[idx], 0, 0);
}

int main(int argc, char *argv[]) {
  __builtin_prefetch(&s.b, 0, 0);
  __builtin_prefetch(&s.c[1], 0, 0);

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int exit_code = atoi(argv[1]);
  
  arg_ptr(&s.c[1]);
  arg_ptr(ptr+3);
  arg_idx(ptr, 3);
  arg_idx(ptr+1, 2);
  idx = 3;
  glob_ptr();
  glob_idx();
  ptr++;
  idx = 2;
  glob_ptr();
  glob_idx();
  exit(exit_code);
}
