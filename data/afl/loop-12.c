// Modification timestamp: 2023-08-14 14:30:05
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/loop-12.c

#include <stdio.h>

char *p;

static int is_end_of_statement(char *ptr) {
  return *ptr == '\n' || *ptr == ';' || *ptr == '!';
}

void foo(char *ptr) {
  while (!is_end_of_statement(ptr))
    ptr++;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  p = argv[1];
  foo(p);
  return 0;
}
