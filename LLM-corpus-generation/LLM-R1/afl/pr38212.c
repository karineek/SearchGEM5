// Modification timestamp: 2023-08-14 15:02:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr38212.c

#include <stdio.h>
#include <stdlib.h>

int __attribute__((noinline))
foo (int *__restrict p, int i)
{
  int *__restrict q;
  int *__restrict r;
  int v, w;
  q = p + 1;
  r = q - i;
  v = *r;
  *p = atoi(argv[1]);
  w = *r;
  return v + w;
}
extern void abort (void);
int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = 0;
  if (foo (&i, 1) != 1)
    abort ();
  return 0;
}

