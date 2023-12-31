// Modification timestamp: 2023-08-14 17:28:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/ms_struct-bitfield-init.c
#include <stdlib.h>

#define ATTR __attribute__((__ms_struct__))

struct
{
   char foo;
   long : 0;
   char : 0;
   int : 0;
   char bar;
} ATTR t1 = {'a', 'b'};

struct
{
   char bar0;
   long : 0;
   int : 0;
   char bar1;
   char bar2;
   long : 0;
   char bar3;
   char bar4;
   char : 0;
   char bar5;
   char bar6;
   char : 0;
   char bar7;
   char bar8;
} ATTR t2 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

struct {
  int : 0;
  int i1;
  int : 0;
  int i2;
  int : 0;
  int i3;
  int : 0;
  int i4;
} ATTR t3 = {1,2,3,4};

int main() {
  if (sizeof(t1) != 2)
    abort();
  if (t1.foo != 'a')
    abort();
  if (t1.bar != 'b')
    abort();
  t1.foo = 'c';
  t1.bar = 'd';
  if (t1.foo != 'c')
    abort();
  if (t1.bar != 'd')
    abort();
  if (sizeof(t2) != 9)
    abort();
  if (t2.bar0 != 'a' || t2.bar8 != 'i')
    abort();
  if (sizeof(t3) != 16)
    abort();
  if (t3.i1 != 1 || t3.i4 != 4)
    abort();
  return 0;
}

