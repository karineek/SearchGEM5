// Modification timestamp: 2023-08-14 13:50:41
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/980612-1.c

#include <stdio.h>
#include <stdlib.h>

struct fd
{
  unsigned char a;
  unsigned char b;
};

struct fd f = { 5 };

struct fd *g(int argc, char *argv[]) {
  return &f;
}

int h(int argc, char *argv[]) {
  return -1;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct fd *f = g(argc, argv);
  f->b = h(argc, argv);
  if (((f->a & 0x7f) & ~0x10) <= 2)
    abort();
  exit(0);
}
