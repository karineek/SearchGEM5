
// Modification timestamp: 2023-08-10 16:40:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/master/MultiSource/Applications/lambda-0.1.3/20000717-5.c

#include <stdio.h>
#include <stdlib.h>

typedef struct trio { int a, b, c; } trio;

int bar (int i, int j, int k, trio t)
{
  if (t.a != 1 || t.b != 2 || t.c != 3 ||
      i != 4 || j != 5 || k != 6)
    abort ();
}

int foo (trio t, int i, int j, int k)
{
  return bar (i, j, k, t);
}

int main(int argc, char *argv[]) {
  if (argc != 7) {
    printf("Usage: %s <a> <b> <c> <i> <j> <k>\n", argv[0]);
    return 1;
  }

  trio t;
  t.a = atoi(argv[1]);
  t.b = atoi(argv[2]);
  t.c = atoi(argv[3]);

  int i = atoi(argv[4]);
  int j = atoi(argv[5]);
  int k = atoi(argv[6]);

  return foo(t, i, j, k);
}
