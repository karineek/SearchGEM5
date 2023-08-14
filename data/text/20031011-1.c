// Modification timestamp: 2023-08-14 12:49:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031011-1.c
/* Check that MAX_EXPR and MIN_EXPR are working properly.  */

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

extern void abort (void);

int main()
{
  int ll_bitsize, ll_bitpos;
  int rl_bitsize, rl_bitpos;
  int end_bit;

  ll_bitpos = 32;  ll_bitsize = 32;
  rl_bitpos = 0;   rl_bitsize = 32;

  end_bit = MAX (ll_bitpos + ll_bitsize, rl_bitpos + rl_bitsize);
  if (end_bit != 64)
    abort ();
  end_bit = MAX (rl_bitpos + rl_bitsize, ll_bitpos + ll_bitsize);
  if (end_bit != 64)
    abort ();
  end_bit = MIN (ll_bitpos + ll_bitsize, rl_bitpos + rl_bitsize);
  if (end_bit != 32)
    abort ();
  end_bit = MIN (rl_bitpos + rl_bitsize, ll_bitpos + ll_bitsize);
  if (end_bit != 32)
    abort ();
  return 0;
}
