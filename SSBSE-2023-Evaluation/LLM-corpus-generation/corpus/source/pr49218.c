// Modification timestamp: 2023-08-14 15:17:53
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr49218.c

#include <stdio.h>
#include <stdlib.h>

#ifdef __SIZEOF_INT128__
typedef __int128 L;
#else
typedef long long L;
#endif

float f;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  L i = (L) atof(argv[1]);
  if (i <= 10)
    do {
      ++i;
      asm("");
    } while (i != 11);

  return 0;
}
