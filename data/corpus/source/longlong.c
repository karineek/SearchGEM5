// Modification timestamp: 2023-08-14 14:29:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/longlong.c

#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long uint64;
unsigned long pars;

uint64 b[32];
uint64 *r = b;

void alpha_ep_extbl_i_eq_0()
{
  unsigned int rb, ra, rc;

  rb = (((unsigned long)(pars) >> 27)) & 0x1fUL;
  ra = (((unsigned int)(pars) >> 5)) & 0x1fUL;
  rc = (((unsigned int)(pars) >> 0)) & 0x1fUL;
  {
    uint64 temp = ((r[ra] >> ((r[rb] & 0x7) << 3)) & 0x00000000000000FFLL);
    if (rc != 31)
      r[rc] = temp;
  }
}

int main(int argc, char *argv[]) {
  if (sizeof (uint64) == 8) {
    if (argc != 2) {
      printf("Usage: %s <value>\n", argv[0]);
      return 1;
    }

    b[17] = atoi(argv[1]);
    b[2] = atoi(argv[2]);

    pars = ((b[17] << 27) & 0xf8000000) | ((b[2] << 5) & 0x07c0) | (b[2] & 0x001f);
    alpha_ep_extbl_i_eq_0();

    if (b[2] != atoi(argv[3]))
      abort ();
  }

  exit (0);
}
