// Modification timestamp: 2023-08-14 14:53:37
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr31169.c

#include <stdio.h>
#include <stdlib.h>

extern void abort();

#define HOST_WIDE_INT long
#define HOST_BITS_PER_WIDE_INT (sizeof(long)*8)

struct tree_type
{
  unsigned int precision : 9;
};

int sign_bit_p(struct tree_type *t, HOST_WIDE_INT val_hi, unsigned HOST_WIDE_INT val_lo)
{
  unsigned HOST_WIDE_INT mask_lo, lo;
  HOST_WIDE_INT mask_hi, hi;
  int width = t->precision;

  if (width > HOST_BITS_PER_WIDE_INT)
  {
    hi = (unsigned HOST_WIDE_INT)1 << (width - HOST_BITS_PER_WIDE_INT - 1);
    lo = 0;

    mask_hi = ((unsigned HOST_WIDE_INT)-1 >> (2 * HOST_BITS_PER_WIDE_INT - width));
    mask_lo = -1;
  }
  else
  {
    hi = 0;
    lo = (unsigned HOST_WIDE_INT)1 << (width - 1);

    mask_hi = 0;
    mask_lo = ((unsigned HOST_WIDE_INT)-1 >> (HOST_BITS_PER_WIDE_INT - width));
  }

  if ((val_hi & mask_hi) == hi && (val_lo & mask_lo) == lo)
    return 1;

  return 0;
}

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("Usage: %s <precision> <val_hi> <val_lo>\n", argv[0]);
    return 1;
  }

  struct tree_type t;
  t.precision = atoi(argv[1]);
  HOST_WIDE_INT val_hi = atoi(argv[2]);
  unsigned HOST_WIDE_INT val_lo = atoi(argv[3]);

  if (!sign_bit_p(&t, val_hi, val_lo))
    abort();

  return 0;
}
