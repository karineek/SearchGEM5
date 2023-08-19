// Modification timestamp: 2023-08-14 15:03:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr38422.c

#include <stdio.h>
#include <stdlib.h>

struct S
{
  int s : (sizeof (int) * __CHAR_BIT__ - 2);
};

void foo(struct S *s)
{
  s->s *= 2;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct S s;
  s.s = atoi(argv[1]);
  foo(&s);
  if (s.s != 48)
    abort ();
  return 0;
}
