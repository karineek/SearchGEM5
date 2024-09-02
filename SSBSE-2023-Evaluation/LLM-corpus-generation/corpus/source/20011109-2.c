// Modification timestamp: 2023-08-14 12:06:25
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20011109-2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <string1> <string2>\n", argv[0]);
    return 1;
  }

  char *c1 = argv[1];
  char *c2 = argv[2];
  int i;
  for (i = 0; i < strlen(c1); i++) {
    if (c1[i] != c2[i])
      abort();
  }
  exit(0);
}
