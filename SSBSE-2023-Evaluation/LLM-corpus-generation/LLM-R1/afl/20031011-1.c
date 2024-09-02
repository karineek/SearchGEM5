// Modification timestamp: 2023-08-14 12:49:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20031011-1.c

#include <stdio.h>
#include <stdlib.h>

#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

extern void abort (void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int ll_bitsize, ll_bitpos;
  int rl_bitsize, rl_bitpos;
  int end_bit;

  ll_bitpos = atoi(argv[1]);  ll_bitsize = atoi(argv[2]);
  rl_bitpos = atoi(argv[3]);   rl_bitsize = atoi(argv[4]);

  end_bit = MAX (ll_bitpos + ll_bitsize, rl_bitpos + rl_bitsize);
  if (end_bit != atoi(argv[5]))
    abort ();
  end_bit = MAX (rl_bitpos + rl_bitsize, ll_bitpos + ll_bitsize);
  if (end_bit != atoi(argv[6]))
    abort ();
  end_bit = MIN (ll_bitpos + ll_bitsize, rl_bitpos + rl_bitsize);
  if (end_bit != atoi(argv[7]))
    abort ();
  end_bit = MIN (rl_bitpos + rl_bitsize, ll_bitpos + ll_bitsize);
  if (end_bit != atoi(argv[8]))
    abort ();
  return 0;
}


Usage: ./program <ll_bitpos> <ll_bitsize> <rl_bitpos> <rl_bitsize> <expected_end_bit1> <expected_end_bit2> <expected_end_bit3> <expected_end_bit4>
