// Modification timestamp: 2023-08-14 15:22:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr52979-2.c

#include <stdio.h>
#include <stdlib.h>

extern void abort (void);
int c, d, e;

void foo(void)
{
}

struct __attribute__((packed)) S {
  int g : 31;
  int h : 6;
};
static struct S b = {1};
struct S a = {1};

void bar(void)
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  a.h = x;
  struct S f = {0};
  b = f;
  e = 0;
  if (y) c = a.g;
}

void baz(void)
{
  bar();
  a = b;
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);
  int y = atoi(argv[2]);
  baz();
  if (a.g) abort();
  return 0;
}
