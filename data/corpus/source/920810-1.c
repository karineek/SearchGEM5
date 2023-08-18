// Modification timestamp: 2023-08-14 13:29:42
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/920810-1.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  void *super;
  int name;
  int size;
} t;

t *f(t *clas, int size) {
  t *child = (t *)malloc(size);
  memcpy(child, clas, clas->size);
  child->super = clas;
  child->name = 0;
  child->size = size;
  return child;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  t foo, *bar;
  memset(&foo, atoi(argv[1]), sizeof(t));
  foo.size = sizeof(t);
  bar = f(&foo, sizeof(t));
  if (bar->super != &foo || bar->name != 0 || bar->size != sizeof(t))
    abort();
  exit(0);
}
