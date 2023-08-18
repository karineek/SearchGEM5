// Modification timestamp: 2023-08-14 14:47:10
// Original Source: https://github.com/llvm/llvm-test-suite/blob/main/SingleSource/Regression/C/gcc-c-torture/execute/pr22348.c

#include <stdio.h>
#include <stdlib.h>

void abort(void);
void f(int i) {
  if (i > atoi(argv[1]) + atoi(argv[2]) * atoi(argv[3])) {
    abort();
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <value1> <value2> <value3>\n", argv[0]);
    return 1;
  }

  unsigned int buflen, i;
  buflen = atoi(argv[1]) + atoi(argv[2]) * atoi(argv[3]);
  for (i = atoi(argv[1]); i < buflen; i += atoi(argv[2])) {
    f(i);
  }
  
  return 0;
}
