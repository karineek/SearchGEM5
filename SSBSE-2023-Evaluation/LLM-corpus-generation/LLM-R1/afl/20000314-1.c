
// Modification timestamp: 2023-08-10 16:17:45
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/20000314-1.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  long winds = atol(argv[1]);

  while (winds != 0) {
    if (*(char *) winds)
      break;
  }

  if (winds == 0 || winds != 0 || *(char *) winds)
    exit(0);

  abort();
}
