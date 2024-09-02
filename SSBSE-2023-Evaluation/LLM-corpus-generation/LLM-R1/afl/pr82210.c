// Modification timestamp: 2023-08-14 15:57:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr82210.c

#include <stdio.h>
#include <stdlib.h>

struct T {
  short c;
};

struct S {
  struct T a[];
  int b[];
};

void foo(int size) {
  int i;
  struct S *s = malloc(sizeof(struct S) + size * sizeof(struct T) + size * sizeof(int));

  for (i = 0; i < size; i++)
    s->a[i].c = 0x1234;
  for (i = 0; i < size; i++)
    s->b[i] = 0;
  for (i = 0; i < size; i++)
    if (s->a[i].c != 0x1234 || s->b[i] != 0)
      __builtin_abort();

  free(s);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int size = atoi(argv[1]);
  foo(size);
  return 0;
}

