// Modification timestamp: 2023-08-14 15:45:58
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr68143_1.c

#include <stdio.h>

struct stuff
{
    int a;
    int b;
    int c;
    int d;
    int e;
    char *f;
    int g;
};

void __attribute__ ((noinline))
bar (struct stuff *x)
{
  if (x->g != 2)
    __builtin_abort ();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct stuff x = {0, 0, 0, 0, 0, NULL, 0};
  x.a = atoi(argv[1]);
  x.d = atoi(argv[2]);
  x.g = atoi(argv[3]);
  /* Struct should now look like {<value>, 0, 0, <value>, 0, NULL, 0, <value>}.  */
  bar(&x);
  return 0;
}
