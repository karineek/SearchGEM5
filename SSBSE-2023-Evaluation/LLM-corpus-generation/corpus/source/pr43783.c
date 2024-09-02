// Modification timestamp: 2023-08-14 15:12:02
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr43783.c

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned long long w[3];
} UINT192;

UINT192 bid_Kx192[32];

extern void abort(void);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int i = 0;
  unsigned long x = atoi(argv[1]);
  for (i = 0; i < 32; ++i)
    bid_Kx192[i].w[1] = x == 1;
  for (i = 0; i < 32; ++i)
    x += bid_Kx192[1].w[1];
  if (x != 32)
    abort();
  return 0;
}
