// Modification timestamp: 2023-08-14 16:02:47
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr86714.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char a[2][3] = { "1234", "xyz" };
char b[6];

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  int x = atoi(argv[1]);

  void *pb = b;

  memcpy(b, a, 4);
  memset(b + 4, 'a', 2);

  if (b[0] != '1' || b[1] != '2' || b[2] != '3'
      || b[3] != 'x' || b[4] != 'a' || b[5] != 'a')
    abort();

  if (memcmp(pb, "123xaa", 6))
    abort();

  return x;
}

