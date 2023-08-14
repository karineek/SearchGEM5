// Modification timestamp: 2023-08-14 14:24:12
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/divcmp-3.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

int test1(char x)
{
  return x/100 == 3;
}

int test1u(unsigned char x)
{
  return x/100 == 3;
}

int test2(char x)
{
  return x/100 != 3;
}

int test2u(unsigned char x)
{
  return x/100 != 3;
}

int test3(char x)
{
  return x/100 < 3;
}

int test3u(unsigned char x)
{
  return x/100 < 3;
}

int test4(char x)
{
  return x/100 <= 3;
}

int test4u(unsigned char x)
{
  return x/100 <= 3;
}

int test5(char x)
{
  return x/100 > 3;
}

int test5u(unsigned char x)
{
  return x/100 > 3;
}

int test6(char x)
{
  return x/100 >= 3;
}

int test6u(unsigned char x)
{
  return x/100 >= 3;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int c = atoi(argv[1]);

  for (c=-128; c<256; c++)
  {
    if (test1(c) != 0)
      abort ();
    if (test1u(c) != 0)
      abort ();
    if (test2(c) != 1)
      abort ();
    if (test2u(c) != 1)
      abort ();
    if (test3(c) != 1)
      abort ();
    if (test3u(c) != 1)
      abort ();
    if (test4(c) != 1)
      abort ();
    if (test4u(c) != 1)
      abort ();
    if (test5(c) != 0)
      abort ();
    if (test5u(c) != 0)
      abort ();
    if (test6(c) != 0)
      abort ();
    if (test6u(c) != 0)
      abort ();
  }
  return 0;
}
