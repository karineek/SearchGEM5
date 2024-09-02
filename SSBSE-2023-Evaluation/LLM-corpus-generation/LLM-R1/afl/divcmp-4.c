// Modification timestamp: 2023-08-14 14:24:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/divcmp-4.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int test1(int x)
{
  return x/-10 == 2;
}

int test2(int x)
{
  return x/-10 == 0;
}

int test3(int x)
{
  return x/-10 != 2;
}

int test4(int x)
{
  return x/-10 != 0;
}

int test5(int x)
{
  return x/-10 < 2;
}

int test6(int x)
{
  return x/-10 < 0;
}

int test7(int x)
{
  return x/-10  <= 2;
}

int test8(int x)
{
  return x/-10 <= 0;
}

int test9(int x)
{
  return x/-10 > 2;
}

int test10(int x)
{
  return x/-10 > 0;
}

int test11(int x)
{
  return x/-10 >= 2;
}

int test12(int x)
{
  return x/-10 >= 0;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  if (test1(x) != 0)
    abort ();
  if (test1(x+1) != 1)
    abort ();
  if (test1(x+10) != 1)
    abort ();
  if (test1(x+11) != 0)
    abort ();

  if (test2(x) != 1)
    abort ();
  if (test2(x+9) != 1)
    abort ();
  if (test2(x+10) != 0)
    abort ();
  if (test2(x-1) != 1)
    abort ();
  if (test2(x-9) != 1)
    abort ();
  if (test2(x-10) != 0)
    abort ();

  if (test3(x) != 1)
    abort ();
  if (test3(x+1) != 0)
    abort ();
  if (test3(x+10) != 0)
    abort ();
  if (test3(x+11) != 1)
    abort ();

  if (test4(x) != 0)
    abort ();
  if (test4(x+9) != 0)
    abort ();
  if (test4(x+10) != 1)
    abort ();
  if (test4(x-1) != 0)
    abort ();
  if (test4(x-9) != 0)
    abort ();
  if (test4(x-10) != 1)
    abort ();

  if (test5(x) != 0)
    abort ();
  if (test5(x+1) != 0)
    abort ();
  if (test5(x+10) != 0)
    abort ();
  if (test5(x+11) != 1)
    abort ();

  if (test6(x) != 0)
    abort ();
  if (test6(x+9) != 0)
    abort ();
  if (test6(x+10) != 1)
    abort ();
  if (test6(x-1) != 0)
    abort ();
  if (test6(x-9) != 0)
    abort ();
  if (test6(x-10) != 0)
    abort ();

  if (test7(x) != 0)
    abort ();
  if (test7(x+1) != 1)
    abort ();
  if (test7(x+10) != 1)
    abort ();
  if (test7(x+11) != 1)
    abort ();

  if (test8(x) != 1)
    abort ();
  if (test8(x+9) != 1)
    abort ();
  if (test8(x+10) != 1)
    abort ();
  if (test8(x-1) != 1)
    abort ();
  if (test8(x-9) != 1)
    abort ();
  if (test8(x-10) != 0)
    abort ();

  if (test9(x) != 1)
    abort ();
  if (test9(x+1) != 0)
    abort ();
  if (test9(x+10) != 0)
    abort ();
  if (test9(x+11) != 0)
    abort ();

  if (test10(x) != 0)
    abort ();
  if (test10(x+9) != 0)
    abort ();
  if (test10(x+10) != 0)
    abort ();
  if (test10(x-1) != 0)
    abort ();
  if (test10(x-9) != 0)
    abort ();
  if (test10(x-10) != 1)
    abort ();

  if (test11(x) != 1)
    abort ();
  if (test11(x+1) != 1)
    abort ();
  if (test11(x+10) != 1)
    abort ();
  if (test11(x+11) != 0)
    abort ();

  if (test12(x) != 1)
    abort ();
  if (test12(x+9) != 1)
    abort ();
  if (test12(x+10) != 0)
    abort ();
  if (test12(x-1) != 1)
    abort ();
  if (test12(x-9) != 1)
    abort ();
  if (test12(x-10) != 1)
    abort ();

  return 0;
}
