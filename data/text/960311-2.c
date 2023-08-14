// Modification timestamp: 2023-08-14 13:45:03
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/960311-2.c
#include <stdio.h>

#ifdef DEBUG
#define abort() printf ("error, line %d\n", __LINE__)
#endif

int count;

void a1() { ++count; }

void
b (unsigned short data)
{
  if (data & 0x8000) a1();
  data <<= 1;

  if (data & 0x8000) a1();
  data <<= 1;

  if (data & 0x8000) a1();
}

main ()
{
  count = 0;
  b (0);
  if (count != 0)
    abort ();

  count = 0;
  b (0x8000);
  if (count != 1)
    abort ();

  count = 0;
  b (0x4000);
  if (count != 1)
    abort ();

  count = 0;
  b (0x2000);
  if (count != 1)
    abort ();

  count = 0;
  b (0xc000);
  if (count != 2)
    abort ();

  count = 0;
  b (0xa000);
  if (count != 2)
    abort ();

  count = 0;
  b (0x6000);
  if (count != 2)
    abort ();

  count = 0;
  b (0xe000);
  if (count != 3)
    abort ();

#ifdef DEBUG
  printf ("Done.\n");
#endif
  exit (0);
}
