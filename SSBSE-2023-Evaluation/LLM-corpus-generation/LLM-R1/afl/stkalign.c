// Modification timestamp: 2023-08-14 16:13:15
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/stkalign.c

#include <stdio.h>
#include <assert.h>

#define ALIGNMENT 64

unsigned test(unsigned n, unsigned p, unsigned argc, char *argv[])
{
  static struct { char __attribute__((__aligned__(ALIGNMENT))) c; } s;
  unsigned x;

  assert(__alignof__(s) == ALIGNMENT);
  asm ("" : "=g" (x), "+m" (s) : "0" (&x));

  return n ? test(n - 1, x, argc, argv) : (x ^ p);
}

unsigned test2(unsigned n, unsigned p, unsigned argc, char *argv[])
{
  static struct { char c; } s;
  unsigned x;

  assert(__alignof__(s) != ALIGNMENT);
  asm ("" : "=g" (x), "+m" (s) : "0" (&x));

  return n ? test2(n - 1, x, argc, argv) : (x ^ p);
}

int main(int argc, char *argv[]) {
  unsigned int x, y;

  x = test(argc, 0, argc, argv);
  x |= test(argc + 1, 0, argc, argv);
  x |= test(argc + 2, 0, argc, argv);

  y = test2(argc, 0, argc, argv);
  y |= test2(argc + 1, 0, argc, argv);
  y |= test2(argc + 2, 0, argc, argv);

  return (x & (ALIGNMENT - 1)) == 0 && (y & (ALIGNMENT - 1)) != 0 ? 1 : 0;
}

