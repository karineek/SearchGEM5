// Modification timestamp: 2023-08-14 13:08:31
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20070212-1.c

#include <stdio.h>
#include <stdlib.h>

struct f {
  int i;
};

int g(int i, int c, struct f *ff, int *p) {
  int *t;
  if (c)
    t = &i;
  else
    t = &ff->i;
  *p = 0;
  return *t;
}

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 6) {
    printf("Usage: %s <int> <int> <int> <int> <int>\n", argv[0]);
    return 1;
  }

  int arg1 = atoi(argv[1]);
  int arg2 = atoi(argv[2]);
  int arg3 = atoi(argv[3]);
  int arg4 = atoi(argv[4]);
  int arg5 = atoi(argv[5]);

  struct f f;
  f.i = arg1;
  if (g(arg2, arg3, &f, &f.i) != arg4) {
    abort();
  }
  return arg5;
}
