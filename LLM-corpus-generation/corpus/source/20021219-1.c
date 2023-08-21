// Modification timestamp: 2023-08-14 12:41:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20021219-1.c
#include <stdlib.h>

#include <stdio.h>

void foo(char *p1, char **p2)
{}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char str[] = "foo { xx }";
  char *ptr = argv[1];

  foo(ptr, &ptr);

  while (*ptr && (*ptr == 13 || *ptr == 32))
    ptr++;

  return 0;
}
