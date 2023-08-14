// Modification timestamp: 2023-08-14 14:41:52
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/nestfunc-7.c

#include <stdio.h>
#include <stdlib.h>

struct A
{
  int one;
  int two;
  int three;
  int four;
  int five;
  int six;
};

static int test(int base)
{
  struct A Foo()
  {
    struct A a;
    a.one = base + 1;
    a.two = base + 2;
    a.three = base + 3;
    a.four = base + 4;
    a.five = base + 5;
    a.six = base + 6;
    return a;
  }

  struct A a = Foo();

  return (a.one == base + 1 &&
          a.two == base + 2 &&
          a.three == base + 3 &&
          a.four == base + 4 &&
          a.five == base + 5 &&
          a.six == base + 6);
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <base>\n", argv[0]);
    return 1;
  }

  int base = atoi(argv[1]);
  return !test(base);
}
