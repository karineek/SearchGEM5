// Modification timestamp: 2023-08-14 17:28:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/156ba07a5c779f6b838dac832a25cf7691898288/SingleSource/UnitTests/ms_struct-bitfield-1.c

#include <stddef.h>
#include <stdio.h>

extern void abort();
#pragma ms_struct on

typedef struct {
  void *pv;
  int l;
} Foo;

typedef struct {
  void *pv1;
  Foo foo;
  unsigned short fInited : 1;
  void *pv2;
} PackOddity;

#pragma ms_struct off

int main(int argc, char *argv[]) {
#pragma unused(argc, argv)

  int sizeof_packoddity = sizeof(PackOddity);
  int offsetof_foo = offsetof(PackOddity, foo);
  int offsetof_pv2 = offsetof(PackOddity, pv2);

  if (sizeof_packoddity != 40)
    abort();
  if (offsetof_foo != 8)
    abort();
  if (offsetof_pv2 != 32)
    abort();

  return 0;
}

