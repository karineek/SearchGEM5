// Modification timestamp: 2023-08-14 15:25:30
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr54985.c

#include <stdio.h>
#include <stdlib.h>

typedef struct st {
  int a;
} ST;

int foo(ST *s, int c, int d)
{
  int first = 1;
  int count = c;
  ST *item = s;
  int a = s->a;
  int x;

  while (count--)
  {
    x = item->a;
    if (first)
      first = 0;
    else if (x >= a)
      return d;
    a = x;
    item++;
  }
  return 0;
}

extern void abort (void);

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("Usage: %s <c> <d> <value>\n", argv[0]);
    return 1;
  }

  int c = atoi(argv[1]);
  int d = atoi(argv[2]);
  ST _1[2] = {{atoi(argv[3])}, {1}};
  if (foo(_1, c, d) != 0)
    abort ();
  return 0;
}
