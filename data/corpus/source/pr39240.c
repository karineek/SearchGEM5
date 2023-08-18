// Modification timestamp: 2023-08-14 15:04:20
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr39240.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

__attribute__((noinline))
static int foo1(int x)
{
  return x;
}

__attribute__((noinline))
unsigned int bar1(int x)
{
  return foo1(x + 6);
}

volatile unsigned long l1 = (unsigned int)-4;

__attribute__((noinline))
static short int foo2(int x)
{
  return x;
}

__attribute__((noinline))
unsigned short int bar2(int x)
{
  return foo2(x + 6);
}

volatile unsigned long l2 = (unsigned short int)-4;

__attribute__((noinline))
static signed char foo3(int x)
{
  return x;
}

__attribute__((noinline))
unsigned char bar3(int x)
{
  return foo3(x + 6);
}

volatile unsigned long l3 = (unsigned char)-4;

__attribute__((noinline))
static unsigned int foo4(int x)
{
  return x;
}

__attribute__((noinline))
int bar4(int x)
{
  return foo4(x + 6);
}

volatile unsigned long l4 = (int)-4;

__attribute__((noinline))
static unsigned short int foo5(int x)
{
  return x;
}

__attribute__((noinline))
short int bar5(int x)
{
  return foo5(x + 6);
}

volatile unsigned long l5 = (short int)-4;

__attribute__((noinline))
static unsigned char foo6(int x)
{
  return x;
}

__attribute__((noinline))
signed char bar6(int x)
{
  return foo6(x + 6);
}

volatile unsigned long l6 = (signed char)-4;

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int value = atoi(argv[1]);
  if (bar1(value) != l1)
    abort();
  if (bar2(value) != l2)
    abort();
  if (bar3(value) != l3)
    abort();
  if (bar4(value) != l4)
    abort();
  if (bar5(value) != l5)
    abort();
  if (bar6(value) != l6)
    abort();
  return 0;
}
