// Modification timestamp: 2023-08-14 14:52:06
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr29156.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
struct test1
{
  int a;
  int b;
};
struct test2
{
  float d;
  struct test1 sub;
};

int global;

int bla(struct test1 *xa, struct test2 *xb)
{
  global = 1;
  xb->sub.a = 1;
  xa->a = 8;
  return xb->sub.a;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct test2 pom;
  int a = atoi(argv[1]);

  if (bla (&pom.sub, &pom) != a)
    abort ();

  return 0;
}
