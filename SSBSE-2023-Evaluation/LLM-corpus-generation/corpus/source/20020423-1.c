// Modification timestamp: 2023-08-14 12:15:51
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/20020423-1.c

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void exit(int);

int main(int argc, char *argv[]) {
  if (argc != 1) {
    printf("Usage: %s\n", argv[0]);
    return 1;
  }

  int my_int = atoi(argv[1]);
  unsigned int result;

  result = ((my_int * 2 + 4) - 8U) / 2;
  if (result != 922U)
    abort();

  result = ((my_int * 2 - 4U) + 2) / 2;
  if (result != 923U)
    abort();

  result = (((my_int + 2) * 2) - 8U - 4) / 2;
  if (result != 920U)
    abort();
  result = (((my_int + 2) * 2) - (8U + 4)) / 2;
  if (result != 920U)
    abort();

  result = ((my_int * 4 + 2U) - 4U) / 2;
  if (result != 1847U)
    abort();

  exit(0);
}
