// Modification timestamp: 2023-08-14 13:47:26
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/961017-2.c

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i = 0;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  if (sizeof(unsigned long int) == 4) {
    unsigned long int z = atoi(argv[1]);

    do {
      z -= 0x00004000;
      i++;
      if (i > 0x00040000)
        abort();
    } while (z > 0);
    exit(0);
  } else if (sizeof(unsigned int) == 4) {
    unsigned int z = atoi(argv[1]);

    do {
      z -= 0x00004000;
      i++;
      if (i > 0x00040000)
        abort();
    } while (z > 0);
    exit(0);
  } else {
    exit(0);
  }
}
