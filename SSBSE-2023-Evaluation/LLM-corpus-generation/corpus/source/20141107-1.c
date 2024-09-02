// Modification timestamp: 2023-08-14 13:22:29
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20141107-1.c

#include <stdio.h>
#include <stdlib.h>

#define bool _Bool

bool f(int a, bool c) __attribute__((noinline));
bool f(int a, bool c)
{
  if (!a)
    c = !c;
  return c;
}

void checkf(int a, bool b)
{
  bool c = f(a, b);
  char d;
  __builtin_memcpy (&d, &c, 1);
  if (d != (a==0)^b)
    __builtin_abort();
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <a> <b>\n", argv[0]);
    return 1;
  }

  int a = atoi(argv[1]);
  bool b = atoi(argv[2]);
  checkf(a, b);
  return 0;
}
