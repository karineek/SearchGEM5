// Modification timestamp: 2023-08-14 17:28:59
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/ms_struct-bitfield-init.c

#include <stdlib.h>

#define ATTR __attribute__((__ms_struct__))

struct {
   char foo;
   long : 0;
   char : 0;
   int : 0;
   char bar;
} ATTR t1;

struct {
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
} ATTR t2;

struct {
  int : 0;
  int i1;
  int : 0;
  int i2;
  int : 0;
  int i3;
  int : 0;
  int i4;
} ATTR t3;

int main(int argc, char *argv[]) {
  if (argc != 10) {
    printf("Usage: %s <foo> <bar0> <bar1> <bar2> <bar3> <bar4> <bar5> <bar6> <bar7> <bar8>\n", argv[0]);
    return 1;
  }

  t1.foo = argv[1][0];
  t1.bar = argv[2][0];

  t2.bar0 = argv[3][0];
  t2.bar1 = argv[4][0];
  t2.bar2 = argv[5][0];
  t2.bar3 = argv[6][0];
  t2.bar4 = argv[7][0];
  t2.bar5 = argv[8][0];
  t2.bar6 = argv[9][0];
  t2.bar7 = argv[10][0];
  t2.bar8 = argv[11][0];

  t3.i1 = atoi(argv[12]);
  t3.i2 = atoi(argv[13]);
  t3.i3 = atoi(argv[14]);
  t3.i4 = atoi(argv[15]);

  if (sizeof(t1) != 2)
    abort();
  if (sizeof(t2) != 9)
    abort();
  if (sizeof(t3) != 16)
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
  if (t2.bar0 != 'a' || t2.bar8 != 'i')
    abort();
  if (t3.i1 != 1 || t3.i4 != 4)
    abort();
  return 0;
}
