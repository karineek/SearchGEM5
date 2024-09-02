// Modification timestamp: 2023-08-14 12:52:21
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20040331-1.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);
void exit(int);

int main(int argc, char *argv[]) {
#if __INT_MAX__ >= 2147483647
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct { int count: 31; } s = { atoi(argv[1]) };
  while (s.count--)
    abort();
#elif __INT_MAX__ >= 32767
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  struct { int count: 15; } s = { atoi(argv[1]) };
  while (s.count--)
    abort();
#else
  /* Don't bother because __INT_MAX__ is too small.  */
#endif
  exit(0);
}
