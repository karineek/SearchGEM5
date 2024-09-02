// Modification timestamp: 2023-08-14 14:25:55
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/doloop-2.c

#include <limits.h>
#include <stdlib.h>

extern void exit(int);
extern void abort(void);

volatile unsigned int i;

int main(int argc, char *argv[]) {
  unsigned short z = 0;

  if (argc != 2) {
    printf("Usage: %s <value>\n", argv[0]);
    return 1;
  }

  unsigned int i = atoi(argv[1]);

  do 
    ++i;
  while (--z > 0);

  if (i != USHRT_MAX + 1U)
    abort();
  exit(0);
}
