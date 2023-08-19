// Modification timestamp: 2023-08-14 15:11:14
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr43236.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void abort(void);
extern void *memset(void *s, int c, __SIZE_TYPE__ n);
extern int memcmp(const void *s1, const void *s2, __SIZE_TYPE__ n);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  char A[30], B[30], C[30];
  int i;

  /* prepare arrays */
  memset(A, atoi(argv[1]), 30);
  memset(B, atoi(argv[1]), 30);

  for (i = 20; i-- > 10;) {
    A[i] = 0;
    B[i] = 0;
  }

  /* expected result */
  memset(C, atoi(argv[1]), 30);
  memset(C + 10, 0, 10);

  /* compare results */
  if (memcmp(A, C, 30) || memcmp(B, C, 30)) abort();
  return 0;
}

