
// Modification timestamp: 2023-08-10 16:39:32
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20000717-1.c

#include <stdlib.h>

typedef struct trio { int a, b, c; } trio;

int
bar (int i, trio t)
{
  if (t.a == t.b || t.a == t.c)
    abort ();
}

int
foo (trio t, int i)
{
  return bar (i, t);
}

int main(int argc, char* argv[])
{
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }

  trio t;
  t.a = atoi(argv[1]);
  t.b = atoi(argv[2]);
  t.c = atoi(argv[3]);

  foo (t, 4);
  exit (0);
}
