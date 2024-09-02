// Modification timestamp: 2023-08-14 15:09:13
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr42512.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);

short g_3;

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int l_2 = atoi(argv[1]);
  for (l_2 = -1; l_2 != 0; l_2 = (unsigned char)(l_2 - 1))
    g_3 |= l_2;
  if (g_3 != -1)
    abort();
  return 0;
}
